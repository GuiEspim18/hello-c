#include <stdio.h>
#include <string.h>


void cleanBuffer(char c) {
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {

    char email[50] ;
    char password[50] ;

    // variable to clean buffer
    char c;

    printf("Digite o seu email: ");
    scanf("%49[^\n]", email);

    // cleaning buffer
    cleanBuffer(c);

    printf("Digite a sua senha: ");
    scanf("%49[^\n]", password);

    // strcmp compare strings
    if (strcmp(email, "user@gmail.com") == 0 && strcmp(password, "123") == 0) {
        printf("Olá user!");
    } else {
        printf("Email ou senha incorretos!");
    }

    return 0;
}