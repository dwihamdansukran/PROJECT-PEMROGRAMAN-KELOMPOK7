#include "header.h"

// Fungsi untuk menampilkan menu admin
void adminMenu()
{
    int choice;
    while (1)
    {
        printf("\nMenu anda:\n");
        printf("1. Tambah Buku\n");
        printf("2. Lihat Buku\n");
        printf("3. Hapus Buku\n");
        printf("4. Edit Buku\n");
        printf("5. Logout\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice)
        {
        case 1:
            tambahBuku();
            break;
        case 2:
            lihatBuku();
            break;
        case 3:
            hapusBuku();
            break;
        case 4:
            editBuku();
            break;
        case 5:
            exit(0);
            return;
        default:
            printf("Pilihan tidak valid.\n");
        }
    }
}

// Fungsi untuk menambahkan buku (admin)
void tambahBuku()
{
    printf("\n--Tambah Buku--\n");
    if (jumlah_buku >= MAX_BUKU)
    {
        printf("\nMaaf, buku tidak dapat ditambahkan.\n");
        return;
    }

    printf("Silahkan masukkan informasi buku\n");
    printf("Id Buku: ");
    scanf("%u", &buku[jumlah_buku].id);
    clearBuffer();

    printf("Judul: ");
    fgets(buku[jumlah_buku].judul, sizeof(buku[jumlah_buku].judul), stdin);
    strtok(buku[jumlah_buku].judul, "\n");

    printf("Penulis: ");
    fgets(buku[jumlah_buku].penulis, sizeof(buku[jumlah_buku].penulis), stdin);
    strtok(buku[jumlah_buku].penulis, "\n");

    printf("Penerbit: ");
    fgets(buku[jumlah_buku].penerbit, sizeof(buku[jumlah_buku].penerbit), stdin);
    strtok(buku[jumlah_buku].penerbit, "\n");

    printf("Jumlah Halaman: ");
    scanf("%u", &buku[jumlah_buku].jumlah_halaman);

    printf("Tahun Terbit: ");
    scanf("%u", &buku[jumlah_buku].tahun_terbit);

    printf("Jumlah Tersedia: ");
    scanf("%u", &buku[jumlah_buku].jumlah_tersedia);

    jumlah_buku++;
    printf("\nBuku berhasil ditambahkan.\n");

    simpanDataBuku(); // Menyimpan data buku ke file "data_perpustakaan.txt"
}

void hapusBuku()
{
    printf("\n--Hapus Buku--\n\n");
    int id_buku;
    printf("Masukkan ID buku yang ingin dihapus: ");
    scanf("%d", &id_buku);
    clearBuffer();

    int index_buku = -1;
    for (int i = 0; i < jumlah_buku; ++i)
    {
        if (buku[i].id == id_buku)
        {
            index_buku = i;
            break;
        }
    }

    if (index_buku == -1)
    {
        printf("\nBuku dengan ID tersebut tidak ditemukan.\n");
        return;
    }

    // Geser array untuk menghapus buku
    for (int i = index_buku; i < jumlah_buku - 1; ++i)
    {
        buku[i] = buku[i + 1];
    }
    jumlah_buku--;

    printf("\nBuku berhasil dihapus.\n");

    // Simpan perubahan ke file
    simpanDataBuku();
}

// Fungsi untuk mengedit buku
void editBuku()
{
    printf("\n--Edit Buku--\n\n");
    int id_buku;
    printf("Masukkan ID buku yang ingin diedit: ");
    scanf("%d", &id_buku);
    clearBuffer();

    int index_buku = -1;
    for (int i = 0; i < jumlah_buku; ++i)
    {
        if (buku[i].id == id_buku)
        {
            index_buku = i;
            break;
        }
    }

    if (index_buku == -1)
    {
        printf("\nBuku dengan ID tersebut tidak ditemukan.\n");
        return;
    }
        // Memperbarui informasi buku
    printf("Silahkan masukkan informasi buku yang baru\n");
    printf("Judul: ");
    fgets(buku[index_buku].judul, sizeof(buku[index_buku].judul), stdin);
    strtok(buku[index_buku].judul, "\n");

    printf("Penulis: ");
    fgets(buku[index_buku].penulis, sizeof(buku[index_buku].penulis), stdin);
    strtok(buku[index_buku].penulis, "\n");

    printf("Penerbit: ");
    fgets(buku[index_buku].penerbit, sizeof(buku[index_buku].penerbit), stdin);
    strtok(buku[index_buku].penerbit, "\n");

    printf("Jumlah Halaman: ");
    scanf("%u", &buku[index_buku].jumlah_halaman);

    printf("Tahun Terbit: ");
    scanf("%u", &buku[index_buku].tahun_terbit);

    printf("Jumlah Tersedia: ");
    scanf("%u", &buku[index_buku].jumlah_tersedia);

    printf("\nBuku berhasil di update.\n");

    // Simpan perubahan ke file
    simpanDataBuku();
}
