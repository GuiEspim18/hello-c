#include <stdio.h>

void showNames() {
    char names[5][20] = { "Guilherme", "Heloisa", "Olívia", "Billy", "Laka" };
    int length = sizeof(names) / sizeof(names[0]);
    for (int i = 0; i < length; i++) {
        printf("\n %s \n", names[i]);
    }
}

int main() {
    showNames();
    return 0;
}