#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct {
    unsigned int book_id;
    char title[100];
    char author[50];
    char publisher[50];
    unsigned int pages;
    unsigned int year;
    unsigned int available_qty;
} Book;

typedef struct {
    char username[20];
    char password[20];
    int is_admin;
} User;

void load_books_from_file();
void save_books_to_file();
int login(char *username, char *password);
void print_books();
void borrow_book(int user_index);
void return_book();

#endif /* LIBRARY_H */
