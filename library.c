#include "header.h"
#include "library.h"

#define MAX_BOOKS 100
#define MAX_USERS 2
#define FILENAME "library_data.txt"

Book books[MAX_BOOKS];
int num_books = 0;

User users[MAX_USERS] = {{"user", "123", 0}, {"admin", "admin123", 1}};

void load_books_from_file() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        exit(1);
    }

    while (fscanf(file, "%u %s %s %s %u %u %u", &books[num_books].book_id, 
            books[num_books].title, books[num_books].author, books[num_books].publisher,
            &books[num_books].pages, &books[num_books].year, &books[num_books].available_qty) != EOF) {
        num_books++;
    }

    fclose(file);
}

void save_books_to_file() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < num_books; i++) {
        fprintf(file, "%u %s %s %s %u %u %u\n", books[i].book_id, books[i].title, books[i].author,
                books[i].publisher, books[i].pages, books[i].year, books[i].available_qty);
    }

    fclose(file);
}

int login(char *username, char *password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return i;
        }
    }
    return -1;
}

void print_books() {
    printf("List Buku Tersedia:\n");
    printf("ID  Judul                           Penulis                 Penerbit            Tahun   Jumlah Tersedia\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("%-4u%-32s%-24s%-20s%-8u%-16u\n", books[i].book_id, books[i].title, books[i].author,
                books[i].publisher, books[i].year, books[i].available_qty);
    }
    printf("\n");
}

void borrow_book(int user_index) {
    unsigned int book_id;
    printf("Masukkan ID buku yang ingin dipinjam: ");
    scanf("%u", &book_id);

    for (int i = 0; i < num_books; i++) {
        if (books[i].book_id == book_id && books[i].available_qty > 0) {
            books[i].available_qty--;
            printf("Buku '%s' berhasil dipinjam.\n", books[i].title);
            save_books_to_file();
            return;
        }
    }

    printf("Buku dengan ID tersebut tidak tersedia atau stok habis.\n");
}

void return_book() {
    unsigned int book_id;
    printf("Masukkan ID buku yang ingin dikembalikan: ");
    scanf("%u", &book_id);

    for (int i = 0; i < num_books; i++) {
        if (books[i].book_id == book_id) {
            books[i].available_qty++;
            printf("Buku '%s' berhasil dikembalikan.\n", books[i].title);
            save_books_to_file();
            return;
        }
    }

    printf("Buku dengan ID tersebut tidak ditemukan.\n");
}
