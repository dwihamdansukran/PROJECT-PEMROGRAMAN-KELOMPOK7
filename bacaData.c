#include "header.h"

// Fungsi untuk membaca data buku dari file teks
void bacaDataBuku()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("Gagal membaca file data buku.\n");
        return;
    }

    while (!feof(file) && jumlah_buku < MAX_BUKU)
    {
        fscanf(file, "Id Buku: %u\n", &buku[jumlah_buku].id);
        fgets(buku[jumlah_buku].judul, sizeof(buku[jumlah_buku].judul), file);
        strtok(buku[jumlah_buku].judul, "\n");
        fgets(buku[jumlah_buku].penulis, sizeof(buku[jumlah_buku].penulis), file);
        strtok(buku[jumlah_buku].penulis, "\n");
        fgets(buku[jumlah_buku].penerbit, sizeof(buku[jumlah_buku].penerbit), file);
        strtok(buku[jumlah_buku].penerbit, "\n");
        fscanf(file, "Jumlah Halaman: %u\n", &buku[jumlah_buku].jumlah_halaman);
        fscanf(file, "Tahun Terbit: %u\n", &buku[jumlah_buku].tahun_terbit);
        fscanf(file, "Jumlah Tersedia: %u\n", &buku[jumlah_buku].jumlah_tersedia);
        jumlah_buku++;
    }

    fclose(file);
}
