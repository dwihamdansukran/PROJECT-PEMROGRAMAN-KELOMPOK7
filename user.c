#include "header.h"

// Struktur untuk buku
typedef struct {
    int IdBuku;
    char judul[255];
    char penulis[100];
    char penerbit[255];
    int jmlHal;
    int tahunTerbit;
    int jumlahBuku;
} Buku;

// Fungsi untuk melihat buku yang tersedia
void lihatBuku() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }
    
    printf("Buku yang tersedia:\n");
    printf("====================\n");
    char line[255];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

// Fungsi untuk meminjam buku
void pinjamBuku() {
    char judul[255];
    printf("Masukkan judul buku yang ingin dipinjam: ");
    fgets(judul, sizeof(judul), stdin);
    judul[strcspn(judul, "\n")] = '\0'; 

    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("File tidak dapat dibuka.\n");
        fclose(file);
        return;
    }

    int found = 0;
    char line[255];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *judulBuku = strtok(line, ",");
        if (strcmp(judulBuku, judul) == 0) {
            found = 1;
            int jumlahBuku;
            sscanf(strtok(NULL, ","), "%d", &jumlahBuku);
            if (jumlahBuku > 0) {
                jumlahBuku--;
                fprintf(tempFile, "%s,%d\n", judulBuku, jumlahBuku);
                printf("Buku '%s' berhasil dipinjam.\n", judul);

                // Tambahkan buku yang dipinjam ke file borrowed_books.txt
                FILE *borrowedFile = fopen("borrowed_books.txt", "a");
                if (borrowedFile == NULL) {
                    printf("File borrowed_books.txt tidak dapat dibuka.\n");
                    fclose(file);
                    fclose(tempFile);
                    return;
                }
                fprintf(borrowedFile, "%s\n", judul);
                fclose(borrowedFile);
            } else {
                printf("Buku tidak tersedia.\n");
            }
        } else {
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (!found) {
        printf("Buku tidak ditemukan.\n");
    }
}

// Fungsi untuk melihat buku yang dipinjam
void lihatBukuDipinjam() {
    FILE *file = fopen("borrowed_books.txt", "r");
    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }
    
    printf("Buku yang dipinjam:\n");
    printf("====================\n");
    char line[255];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

// Fungsi untuk mengembalikan buku
void kembaliBuku() {
    char judul[255];
    printf("Masukkan judul buku yang ingin dikembalikan: ");
    fgets(judul, sizeof(judul), stdin);
    judul[strcspn(judul, "\n")] = '\0';
    
    FILE *file = fopen("books.txt", "r+");
    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }
    
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("File tidak dapat dibuka.\n");
        fclose(file);
        return;
    }
    
    int found = 0;
    char line[255];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *judulBuku = strtok(line, ",");
        if (strcmp(judulBuku, judul) == 0) {
            found = 1;
            int jumlahBuku;
            sscanf(strtok(NULL, ","), "%d", &jumlahBuku);
            jumlahBuku++;
            fprintf(tempFile, "%s,%d\n", judulBuku, jumlahBuku);
            printf("Buku '%s' berhasil dikembalikan.\n", judul);
        } else {
            fprintf(tempFile, "%s", line);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove("books.txt");
    rename("temp.txt", "books.txt");
    
    if (!found) {
        printf("Buku tidak ditemukan.\n");
    }
}

int main (){
    int pilihan;
    printf("Menu User:\n");
    printf("1. Lihat buku\n");
    printf("2. Pinjam buku\n");
    printf("3. Lihat buku yang dipinjam\n");
    printf("4. Kembalikan buku\n");
    printf("5. Keluar\n");
    printf("Pilih opsi: ");
    
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &pilihan);
    
    switch (pilihan) {
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
            kembaliBuku();
            break;
        case 5:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Opsi tidak valid.\n");
    }
    
    return 0;
}
