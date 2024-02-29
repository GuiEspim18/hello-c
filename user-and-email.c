#include <stdio.h>

int main() {

    char email[50] ;
    char password[50] ;

    printf("Digite o seu email: ");
    scanf("%49[^\n]", email);

    printf("Digite a sua senha: ");
    scanf("%49[^\n]", password);

    if (email == "user@gmail.com" && password == "123") {
        printf("Olá user!");
    } else {
        printf("Email ou senha incorretos!");
    }

    return 0;
}