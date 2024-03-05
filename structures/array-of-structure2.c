#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Car {
    int id;
    char brand[100];
    char model[100];
    char price[10];
};

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char* scan(char title[10], int size) {
    printf("%s: ", title);
    static char variable[100]; // Definindo um tamanho fixo para o array
    scanf("%99[^\n]", variable);
    clearBuffer();
    return variable;
}

int main() {
    printf("----Cadastro de carros----\n");
    struct Car *cars;

    for (;;) {
        char stop;

        char *brand = scan("Marca", 100); // Alterado para char*
        char *model = scan("Modelo", 100); // Alterado para char*
        char *price = scan("Preço", 10); // Alterado para char*

        printf("%s\n", brand); // Corrigido para imprimir corretamente
        printf("%s\n", model); // Corrigido para imprimir corretamente
        printf("%s\n", price); // Corrigido para imprimir corretamente

        break;
    }

    return 0;
}
