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

void scan(char title[10], char variable[], int size) {
    printf("%s: ", title);
    scanf("%99[^\n]", variable);
    clearBuffer();
}

int main() {
    printf("----Cadastro de carros----\n");
    struct Car *cars;

    for (;;) {
        char stop;

        char brand[100];
        char model[100];
        char price[10];

        scan("Marca", brand, 100);
        scan("Modelo", model, 100);
        scan("Preço", price, 10);

        printf("%s\n", brand);
        printf("%s\n", model);
        printf("%s\n", price);

        break;
    }

    return 0;
}
