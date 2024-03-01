#include <stdio.h>

int main() {
    int value1;
    int value2;

    printf("Digite um valor: ");
    scanf("%d", &value1);

    printf("Digite outro valor: ");
    scanf("%d", &value2);

    int result = value1 + value2;

    printf("%d + %d = %d", value1, value2, result);

    return 0;
}