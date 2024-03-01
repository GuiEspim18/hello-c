#include <stdio.h>
#include <string.h>

void clearBuffer() {
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {

    char string[50];

    printf("Digite o seu nome: ");
    scanf("%49[^\n]", string);
    clearBuffer();
  
    if (strcmp(string, "Guilherme") == 0) {
        printf("Olá Guilherme\n");
    } else {
        printf("Não é o Guilherme\n");
    }

    return 0;
}