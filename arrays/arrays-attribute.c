#include <stdio.h>

int main() {

    int numbers[5];

    for (int i = 0; i < 5; i++) {
        numbers[i] = i + 1;
    }

    printf("Elementos do array: ");

    for (int i = 0; i < 5; i++) {
        printf(" %d", numbers[i]);
    }

    printf("\n");

    return 0;
}