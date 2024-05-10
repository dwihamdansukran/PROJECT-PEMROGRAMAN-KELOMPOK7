#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }

    load_books_from_file(); 

    int user_index = login(argv[1], argv[2]); 
    if (user_index == -1) {
        printf("Login gagal. Periksa kembali username dan password Anda.\n");
        return 1;
    }

    printf("Login berhasil.\n");

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Lihat Buku Tersedia\n");
        printf("2. Pinjam Buku\n");
        printf("3. Kembalikan Buku\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_books();
                break;
            case 2:
                borrow_book(user_index);
                break;
            case 3:
                return_book();
                break;
            case 4:
                printf("Terima kasih telah menggunakan layanan kami.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 4);

    return 0;
}
