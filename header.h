#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned int id;
    char judul[100];
    char penulis[50];
    char penerbit[50];
    unsigned int jumlah_halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_tersedia;
} Buku;

void tambahkan_buku(Buku daftar_buku[], int *jumlah_buku);
void hapus_buku(Buku daftar_buku[], int *jumlah_buku);
void edit_buku(Buku daftar_buku[], int jumlah_buku);
void simpan_ke_file(Buku daftar_buku[], int jumlah_buku);
void baca_dari_file(Buku daftar_buku[], int *jumlah_buku);
