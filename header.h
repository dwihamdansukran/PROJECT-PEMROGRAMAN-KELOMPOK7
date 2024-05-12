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

#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct {
    char username[20];
    char password[20];
    int is_admin;
} User;

void load_books_from_file();
void save_books_to_file();
int login(char *username, char *password);
void print_books();
void borrow_book(int user_index);
void return_book();

#endif

