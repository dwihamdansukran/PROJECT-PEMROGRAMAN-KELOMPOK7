#include "header.h"

char Login ( ) {
    char pass [ ] = {"password"}; //untuk password nya , ketika login kata "password" ini yg menentukan berhasil atau gagal
    char akun;
    char username [256];
    char password[256];
    printf ("login sebagai admin atau user [a/u] ?\n");
    scanf ("%c",&akun);
    
    printf("USERNAME: ");
    scanf (" %s", username);
    printf("\nPASSWORD: ");
    scanf (" %s", password);
    

    if (strcmp(password , pass ) == 0) {
        printf("Login success!!\n");
        
    }
    else {
        printf("ERROR!PASSWORD ATAU USERNAME SALAH!\n");
        EXIT_FAILURE;
    }

}

int main (){
    Login ();
}
