#include "header.h"

// Fungsi untuk membersihkan buffer input
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
