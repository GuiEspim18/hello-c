#include <stdio.h>

int main() {
    printf("Tabuada do 2: ");
    int num = 0;
    do {
        int result = num * 2;
        printf("\n%d x 2 = %d", num, result);
        num++;
    } while(num <= 10);
    return 0;
}