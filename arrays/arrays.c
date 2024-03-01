#include <stdio.h>

int main() {
    int numbers[5] = { 5, 4 ,3 ,2 ,1 };
    printf("Elementos do array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d", numbers[i]);
    }
    printf("\n");
    return 0;
}