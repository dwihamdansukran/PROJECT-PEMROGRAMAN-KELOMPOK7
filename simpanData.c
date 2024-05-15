#include "header.h"

// Fungsi untuk menyimpan data buku ke file
void simpanDataBuku()
{
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL)
    {
        printf("\nGagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_buku; ++i)
    {
        fprintf(file, "Id Buku: %u\n", buku[i].id);
        fprintf(file, "Judul: %s\n", buku[i].judul);
        fprintf(file, "Penulis: %s\n", buku[i].penulis);
        fprintf(file, "Penerbit: %s\n", buku[i].penerbit);
        fprintf(file, "Jumlah Halaman: %u\n", buku[i].jumlah_halaman);
        fprintf(file, "Tahun Terbit: %u\n", buku[i].tahun_terbit);
        fprintf(file, "Jumlah Tersedia: %u\n", buku[i].jumlah_tersedia);
    }

    fclose(file);
}
