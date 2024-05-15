#include "header.h"

Buku buku[MAX_BUKU];
int jumlah_buku = 0;
int jumlah_user = 0;
int jumlah_buku_dipinjam = 0;
Buku buku_dipinjam[MAX_BUKU_DIPINJAM];

int main()
{
    bacaDataBuku(); 

    login();

    return 0;
}
