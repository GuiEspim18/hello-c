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

char scan(char title[10], int size) {
    printf("%s: ", title);
    char variable[size];
    scanf("%99[^\n]", variable);
    return variable;
}

int main() {
    printf("----Cadastro de carros----\n");
    struct Car *cars;

    for (;;) {
        char stop;

        char brand = scan("Marca", 100);
            clearBuffer();
        char model = scan("Modelo", 100);
            clearBuffer();
        char price = scan("Preço", 10);
            clearBuffer();

        printf(brand);
        printf(model);
        printf(price);

        break;
        
    }

    return 0;
}