#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


// Struktur untuk buku
typedef struct {
    int IdBuku;
    char judul[255];
    char penulis[100];
    char penerbit[255];
    int jmlHal;
    int tahunTerbit;
    int jumlahBuku;
} Buku;

// Struktur untuk buku yang dipinjam
typedef struct {
    char judul[255];
    char penulis[100];
    int tahunTerbit;
    int jumlahBuku;
    int status;
} BukuDipinjam;

// Variabel untuk menyimpan data
Buku buku[255];
BukuDipinjam bukuDipinjam[255];
int jumlahAkun = 0;
int jumlahBuku = 0;
int jumlahBukuDipinjam = 0;

// Fungsi untuk melihat buku
void lihatBuku() {
    printf("Daftar buku:\n");
    for (int i = 0; i < jumlahBuku; i++) {
        printf("%s - %s - %d - %d\n", buku[i].judul, buku[i].penulis, buku[i].tahunTerbit, buku[i].jumlahBuku);
    }
}

// Mendefinisikan array buku dan jumlah buku
Buku buku[255];
int jumlahBuku = 0;

// Mendefinisikan array buku yang sedang dipinjam dan jumlah buku yang dipinjam
BukuDipinjam bukuDipinjam[100];
int jumlahBukuDipinjam = 0;

// Fungsi untuk menyimpan data buku ke dalam file
void tulisData() {
    FILE *file = fopen("books.txt", "a");
    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    fprintf(file, "%d\n", jumlahBuku);
    for (int i = 0; i < jumlahBuku; i++) {
        fprintf(file, "%s %s %d %d\n", buku[i].judul, buku[i].penulis, buku[i].tahunTerbit, buku[i].jumlahBuku);
    }

    fclose(file);
}

// Fungsi untuk meminjam buku
void pinjamBuku() {
    char judul[255];
    printf("Masukkan judul buku yang ingin dipinjam: ");
    fgets(judul, sizeof(judul), stdin);
    judul[strcspn(judul, "\n")] = '\0'; 
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(buku[i].judul, judul) == 0) {
            if (buku[i].jumlahBuku > 0) {
                strcpy(bukuDipinjam[jumlahBukuDipinjam].judul, buku[i].judul);
                strcpy(bukuDipinjam[jumlahBukuDipinjam].penulis, buku[i].penulis);
                bukuDipinjam[jumlahBukuDipinjam].tahunTerbit = buku[i].tahunTerbit;
                bukuDipinjam[jumlahBukuDipinjam].jumlahBuku = buku[i].jumlahBuku;
                bukuDipinjam[jumlahBukuDipinjam].status = 1;
                jumlahBukuDipinjam++;
                buku[i].jumlahBuku--;
                tulisData();
                return;
            } else {
                printf("Buku tidak tersedia.\n");
                return;
            }
        }
    }
    printf("Buku tidak ditemukan.\n");
}


// Fungsi untuk melihat buku yang dipinjam
void lihatBukuDipinjam() {
    printf("Daftar buku yang dipinjam:\n");
    for (int i = 0; i < jumlahBukuDipinjam; i++) {
        printf("%s - %s - %d - %d - %d\n", bukuDipinjam[i].judul, bukuDipinjam[i].penulis, bukuDipinjam[i].tahunTerbit, bukuDipinjam[i].jumlahBuku, bukuDipinjam[i].status);
    }
}

// Fungsi untuk mengembalikan buku
void kembaliBuku() {
    char judul[255];
    printf("Masukkan judul buku yang ingin dikembalikan: ");
    fgets(judul, sizeof(judul), stdin);
    judul[strcspn(judul, "\n")] = '\0';
    for (int i = 0; i < jumlahBukuDipinjam; i++) {
        if (strcmp(bukuDipinjam[i].judul, judul) == 0) {
            bukuDipinjam[i].status = 0;
            bukuDipinjam[i].jumlahBuku++;
            tulisData();
            return;
        }
    }
    printf("Buku tidak ditemukan.\n");
} 

// Fungsi untuk menu user
void userMenu() {
    int pilihan;
    printf("Menu User:\n");
    printf("1. Lihat buku\n");
    printf("2. Pinjam buku\n");
    printf("3. Lihat buku yang dipinjam\n");
    printf("4. Kembali ke menu utama\n");
    printf("Pilih opsi: ");
    scanf("%d", &pilihan);
    switch (pilihan) {
        case 1:
            lihatBuku();
            break;
        case 2:
            pinjamBuku();
            break;
        case 3:
            lihatBukuDipinjam();
            break;
        case 4:
            login();
            break;
        default:
            printf("Opsi tidak valid.\n");
            userMenu();
    }
}
