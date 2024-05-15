#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifndef LIBRARY_H
#define LIBRARY_H

#define FILENAME "books.txt"
#define MAX_BUKU 100
#define MAX_BUKU_DIPINJAM 10

// Struktur untuk menyimpan informasi buku
typedef struct {
    unsigned int id;
    char judul[100];
    char penulis[100];
    char penerbit[100];
    unsigned int jumlah_halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_tersedia;
} Buku;

extern Buku buku[MAX_BUKU];
extern int jumlah_buku;
extern int jumlah_user;
extern int jumlah_buku_dipinjam;
extern Buku buku_dipinjam[MAX_BUKU_DIPINJAM];

// Struktur untuk menyimpan informasi user
struct User {
    char username[100];
    char password[100];
    int isAdmin;
};

// Fungsi admin
void tambahBuku();
void hapusBuku();
void editBuku();

// Fungsi user
void lihatBuku();
void pinjamBuku();
void lihatBukuDipinjam();
void kembalikanBuku();

// Fungsi tambahan
void login();
void adminMenu();
void userMenu();
void simpanDataBuku();
void bacaDataBuku();
void clearBuffer();


#endif
