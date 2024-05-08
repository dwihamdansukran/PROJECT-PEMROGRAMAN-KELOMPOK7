#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
    int choice;
    char username[MAX_LENGTH], password[MAX_LENGTH];
    char filename[MAX_LENGTH];

    printf("Selamat datang di program login.\n");
    printf("Pilih jenis akun:\n");
    printf("1. Admin\n");
    printf("2. User\n");
    printf("Masukkan pilihan (1 atau 2): ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Pilihan tidak valid.\n");
        return 1;
    }

    // Menentukan nama file berdasarkan pilihan akun yaitu admin.txt atau user.txt
    if (choice == 1) {
        strcpy(filename, "admin.txt");
    } else {
        strcpy(filename, "user.txt");
    }

    // Membuka file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    // Meminta username dan password 
    printf("Masukkan username: ");
    getchar(); // Membersihkan buffer keyboard
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Menghapus karakter newline dari username
    printf("Masukkan password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Menghapus karakter newline dari password

    // Memeriksa username dan password dalam file
    char line[MAX_LENGTH];
    int LogIn = 0;
    while (fgets(line, sizeof(line), file)) {
        char *storedUsername = strtok(line, ","); //fungsi strtok berguna untuk memisahkan satu baris menjadi dua bagian dengan koma
        char *storedPassword = strtok(NULL, "\n");

        // Membandingkan username dan password
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            LogIn = 1;
            break;
        }
    }

    // Menampilkan hasil login
    if (LogIn) {
        printf("Login berhasil sebagai %s.\n", (choice == 1) ? "admin" : "user");
    } else {
        printf("Login gagal. Username atau password salah.\n");
    }

    // Menutup file
    fclose(file);

    return 0;
}

