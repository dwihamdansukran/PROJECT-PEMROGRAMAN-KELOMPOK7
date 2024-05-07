#include "header.h"

//Struktur untuk menyimpan informasi tentang buku
typedef struct 
{
    unsigned int id;
    char judul[100];
    char penulis[50];
    char penerbit[50];
    unsigned int jumlah_halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_tersedia;
}Buku;


// Fungsi untuk menambahkan buku baru
void tambahkan_buku(Buku daftar_buku[], int *jumlah_buku) {
    printf("Masukkan ID buku: ");
    scanf("%u", &daftar_buku[*jumlah_buku].id);
    printf("Masukkan judul buku: ");
    scanf(" %[^\n]s", daftar_buku[*jumlah_buku].judul);
    printf("Masukkan penulis buku: ");
    scanf(" %[^\n]s", daftar_buku[*jumlah_buku].penulis);
    printf("Masukkan penerbit buku: ");
    scanf(" %[^\n]s", daftar_buku[*jumlah_buku].penerbit);
    printf("Masukkan jumlah halaman buku: ");
    scanf("%u", &daftar_buku[*jumlah_buku].jumlah_halaman);
    printf("Masukkan tahun terbit buku: ");
    scanf("%u", &daftar_buku[*jumlah_buku].tahun_terbit);
    printf("Masukkan jumlah buku yang tersedia: ");
    scanf("%u", &daftar_buku[*jumlah_buku].jumlah_tersedia);

    (*jumlah_buku)++;
    printf("Buku berhasil ditambahkan!\n");
}

// Fungsi untuk menghapus buku
void hapus_buku(Buku daftar_buku[], int *jumlah_buku) {
    unsigned int id_hapus;
    printf("Masukkan ID buku yang ingin dihapus: ");
    scanf("%u", &id_hapus);

    // Cari buku berdasarkan ID
    int index = -1;
    for (int i = 0; i < *jumlah_buku; i++) {
        if (daftar_buku[i].id == id_hapus) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Geser semua elemen setelah buku yang dihapus
        for (int i = index; i < *jumlah_buku - 1; i++) {
            daftar_buku[i] = daftar_buku[i + 1];
        }
        (*jumlah_buku)--;
        printf("Buku berhasil dihapus!\n");
    } else {
        printf("Buku tidak ditemukan.\n");
    }
}

// Fungsi untuk mengedit informasi buku
void edit_buku(Buku daftar_buku[], int jumlah_buku) {
    unsigned int id_edit;
    printf("Masukkan ID buku yang ingin diedit: ");
    scanf("%u", &id_edit);

    // Cari buku berdasarkan ID
    int index = -1;
    for (int i = 0; i < jumlah_buku; i++) {
        if (daftar_buku[i].id == id_edit) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Masukkan judul baru buku: ");
        scanf(" %[^\n]s", daftar_buku[index].judul);
        printf("Masukkan penulis baru buku: ");
        scanf(" %[^\n]s", daftar_buku[index].penulis);
        printf("Masukkan penerbit baru buku: ");
        scanf(" %[^\n]s", daftar_buku[index].penerbit);
        printf("Masukkan jumlah halaman baru buku: ");
        scanf("%u", &daftar_buku[index].jumlah_halaman);
        printf("Masukkan tahun terbit baru buku: ");
        scanf("%u", &daftar_buku[index].tahun_terbit);
        printf("Masukkan jumlah buku yang tersedia: ");
        scanf("%u", &daftar_buku[index].jumlah_tersedia);

        printf("Buku berhasil diedit!\n");
    } else {
        printf("Buku tidak ditemukan.\n");
    }
}

int main() {
    Buku daftar_buku[100]; //deklasari variabel
    int jumlah_buku = 0;
    int pilihan;

    do {
        //Tampilan menu admin 
        printf("\nMenu admin :\n");
        printf("1. Tambah Buku \n");
        printf("2. Hapus Buku\n");
        printf("3. Edit Buku\n");
        printf("4. Keluar\n");
        scanf("%d", &pilihan);

        //proses pilihan admin
        switch (pilihan) {
         case 1:
            tambahkan_buku(daftar_buku, &jumlah_buku);
            break;
        case 2:
            hapus_buku(daftar_buku, &jumlah_buku);
            break;
        case 3: 
            edit_buku(daftar_buku, jumlah_buku);
            break;
        case 4:
            printf("Terima Kasih.\n");
            break;
        default :
            printf("Pilihan tidak valid.\n");
        }   

     }  while (pilihan != 4); 

     return 0;
}
