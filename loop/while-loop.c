#include <stdio.h>

int main() {
    printf("Todos os números pares de 2 a 20");
    int num = 2;
    while (num <= 20) {
        printf("\n%d ", num);
        num += 2;
    }
    printf("\n");
    return 0;
}