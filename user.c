#include "header.h"

// Fungsi untuk menampilkan menu user
void userMenu()
{
    int choice;
    while (1)
    {
        printf("\nMenu Anda: \n");
        printf("1. Lihat Buku\n");
        printf("2. Pinjam Buku\n");
        printf("3. Lihat Buku yang Dipinjam\n");
        printf("4. Kembalikan Buku\n");
        printf("5. Logout\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice)
        {
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
            kembalikanBuku();
            break;
        case 5:
            printf("Terimakasih telah mengunjungi perpustakaan kami.\n");
            exit(0);
            return;
        default:
            printf("Pilihan tidak valid.\n");
        }
    }
}

// Fungsi untuk melihat daftar buku
void lihatBuku()
{
    printf("\n--Daftar Buku yang Tersedia--\n\n");
    for (int i = 0; i < jumlah_buku; ++i)
    {
        int isDipinjam = 0;
        for (int j = 0; j < jumlah_buku_dipinjam; ++j)
        {
            if (buku[i].id == buku_dipinjam[j].id)
            {
                isDipinjam = 1;
                break;
            }
        }
        if (!isDipinjam)
        {
            printf("Id Buku: %u\n", buku[i].id);
            printf("%s\n", buku[i].judul);
            printf("%s\n", buku[i].penulis);
            printf("%s\n", buku[i].penerbit);
            printf("Jumlah Halaman: %u\n", buku[i].jumlah_halaman);
            printf("Tahun Terbit: %u\n", buku[i].tahun_terbit);
            printf("Jumlah Tersedia: %u\n\n", buku[i].jumlah_tersedia);
        }
    }
}

// Fungsi untuk melakukan peminjaman buku
void pinjamBuku()
{
    printf("\n--Pinjam Buku--\n\n");

    if (jumlah_buku_dipinjam >= MAX_BUKU_DIPINJAM)
    {
        printf("Maaf, Anda telah mencapai batas maksimal peminjaman buku.\n");
        return;
    }

    int id_buku;
    printf("Masukkan ID buku yang ingin dipinjam: ");
    scanf("%d", &id_buku);
    clearBuffer();

    // Cek apakah buku tersedia dan masih bisa dipinjam
    int index_buku = -1;
    for (int i = 0; i < jumlah_buku; ++i)
    {
        if (buku[i].id == id_buku)
        {
            if (buku[i].jumlah_tersedia > 0)
            {
                index_buku = i;
                break;
            }
            else
            {
                printf("\nMaaf, buku yang anda maksud sedang tidak tersedia.\n");
                return;
            }
        }
    }

    if (index_buku == -1)
    {
        printf("\nBuku dengan ID tersebut tidak ditemukan.\n");
        return;
    }

    // Tambahkan buku yang dipinjam ke dalam list buku yang sedang dipinjam
    buku_dipinjam[jumlah_buku_dipinjam++] = buku[index_buku];
    buku[index_buku].jumlah_tersedia--;
    printf("\nBuku berhasil dipinjam.\n");
}

// Fungsi untuk melihat daftar buku yang dipinjam
void lihatBukuDipinjam()
{
    printf("\n--Buku yang Dipinjam--\n\n");
    if (jumlah_buku_dipinjam == 0)
    {
        printf("Anda belum meminjam buku apapun.\n");
        return;
    }

    for (int i = 0; i < jumlah_buku_dipinjam; ++i)
    {
        printf("Id Buku: %u\n", buku_dipinjam[i].id);
        printf("Judul: %s\n", buku_dipinjam[i].judul);
        printf("Penulis: %s\n", buku_dipinjam[i].penulis);
        printf("Penerbit: %s\n", buku_dipinjam[i].penerbit);
        printf("Jumlah Halaman: %u\n", buku_dipinjam[i].jumlah_halaman);
        printf("Tahun Terbit: %u\n", buku_dipinjam[i].tahun_terbit);
        printf("\n");
    }
}

// Fungsi untuk mengembalikan buku
void kembalikanBuku()
{
    printf("\n--Kembalikan Buku--\n\n");
    if (jumlah_buku_dipinjam == 0)
    {
        printf("Anda belum meminjam buku apapun.\n");
        return;
    }

    int id_buku;
    printf("Masukkan ID buku yang ingin dikembalikan: ");
    scanf("%d", &id_buku);
    clearBuffer();

    int index_buku = -1;
    for (int i = 0; i < jumlah_buku_dipinjam; ++i)
    {
        if (buku_dipinjam[i].id == id_buku)
        {
            index_buku = i;
            break;
        }
    }

    if (index_buku == -1)
    {
        printf("\nBuku dengan ID tersebut tidak ditemukan dalam daftar buku yang Anda pinjam.\n");
        return;
    }

    // Kembalikan buku ke daftar buku yang tersedia dan hapus dari daftar buku yang dipinjam
    buku[index_buku].jumlah_tersedia++;
    for (int i = index_buku; i < jumlah_buku_dipinjam - 1; ++i)
    {
        buku_dipinjam[i] = buku_dipinjam[i + 1];
    }
    jumlah_buku_dipinjam--;
    printf("\nBuku berhasil dikembalikan.\n");

    userMenu(); 
}
