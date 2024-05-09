#include "header.h"

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

int main() {
    Buku daftar_buku[100];
    int jumlah_buku = 0;
    int pilihan;

    // Membaca data dari file teks saat program dimulai
    baca_dari_file(daftar_buku, &jumlah_buku);

    do {
        printf("\nMenu admin :\n");
        printf("1. Tambah Buku \n");
        printf("2. Hapus Buku\n");
        printf("3. Edit Buku\n");
        printf("4. Simpan & Keluar\n");
        printf("");
        scanf("%d", &pilihan);

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
                // Simpan data ke dalam file sebelum keluar
                simpan_ke_file(daftar_buku, jumlah_buku);
                printf("Terima Kasih.\n");
                break;
            default :
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 4);

    return 0;
}

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

void hapus_buku(Buku daftar_buku[], int *jumlah_buku) {
    unsigned int id_hapus;
    printf("Masukkan ID buku yang ingin dihapus: ");
    scanf("%u", &id_hapus);

    int index = -1;
    for (int i = 0; i < *jumlah_buku; i++) {
        if (daftar_buku[i].id == id_hapus) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < *jumlah_buku - 1; i++) {
            daftar_buku[i] = daftar_buku[i + 1];
        }
        (*jumlah_buku)--;
        printf("Buku berhasil dihapus!\n");
    } else {
        printf("Buku tidak ditemukan.\n");
    }
}

void edit_buku(Buku daftar_buku[], int jumlah_buku) {
    unsigned int id_edit;
    printf("Masukkan ID buku yang ingin diedit: ");
    scanf("%u", &id_edit);

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

void simpan_ke_file(Buku daftar_buku[], int jumlah_buku) {
    FILE *file = fopen("daftar_buku.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_buku; i++) {
        fprintf(file, "%u;%s;%s;%s;%u;%u;%u\n", 
                daftar_buku[i].id,
                daftar_buku[i].judul,
                daftar_buku[i].penulis,
                daftar_buku[i].penerbit,
                daftar_buku[i].jumlah_halaman,
                daftar_buku[i].tahun_terbit,
                daftar_buku[i].jumlah_tersedia);
    }

    fclose(file);
    printf("Data buku berhasil disimpan ke dalam file.\n");
}

void baca_dari_file(Buku daftar_buku[], int *jumlah_buku) {
    FILE *file = fopen("daftar_buku.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    // Loop untuk membaca setiap baris dari file
    while (fscanf(file, "%u;%[^;];%[^;];%[^;];%u;%u;%u\n",
                  &daftar_buku[*jumlah_buku].id,
                  daftar_buku[*jumlah_buku].judul,
                  daftar_buku[*jumlah_buku].penulis,
                  daftar_buku[*jumlah_buku].penerbit,
                  &daftar_buku[*jumlah_buku].jumlah_halaman,
                  &daftar_buku[*jumlah_buku].tahun_terbit,
                  &daftar_buku[*jumlah_buku].jumlah_tersedia) == 7) {
        (*jumlah_buku)++; // Menambah jumlah_buku setiap kali sebuah buku dibaca
    }

    fclose(file);
    printf("Data buku berhasil dimuat dari file.\n");
}
