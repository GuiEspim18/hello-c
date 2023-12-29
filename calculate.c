#include <stdio.h>

// prototype calculateFatorial function
int calculateFatorial(int value);

int main() {
    int value;

    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &value);

    int result = calculateFatorial(value);

    printf("O fatorial de %d é: %d\n", value, result);
    return 0;
}

int calculateFatorial (int value) {
    if (value == 0) {
        return 1;
    } else {
        return value * calculateFatorial(value - 1);
    }
}