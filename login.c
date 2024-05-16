#include <stdio.h>
#include <string.h>
#include "header.h"

// Fungsi untuk masuk
void login()
{
    char username[100];
    char password[100];

    printf("\n--------------------------------------------------------");
    printf("\nSelamat Datang di Sistem Peminjaman Buku Perpustakaan");
    printf("\n--------------------------------------------------------\n");


    printf("\nUsername : ");
    scanf("%s", username);
    clearBuffer();

    printf("Password : ");
    scanf("%s", password);
    clearBuffer();

    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file users.txt.\n");
        return;
    }

    int loggedIn = 0;
    char file_username[100];
    char file_password[100];
    int isAdmin;
    while (fscanf(file, "%s %s %d", file_username, file_password, &isAdmin) != EOF) {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            loggedIn = 1;
            if (isAdmin) {
                printf("\nLogin berhasil! Anda masuk sebagai Admin.\n");
                adminMenu();
            } else {
                printf("\nLogin berhasil! Anda masuk sebagai User\n");
                userMenu(); 
            }
            break;
        }
    }

    fclose(file);

    if (!loggedIn) {
        printf("Username tidak ditemukan atau password yang dimasukkan salah. Silakan coba lagi.\n");
        login();
    }
}

