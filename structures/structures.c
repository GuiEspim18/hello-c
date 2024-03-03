#include <stdio.h>

struct Person {
    int age;
    char name[100];
};

int main() {
    struct Person person1 = { 21, "Guilherme" };
    struct Person person2 = { 20, "Heloisa" };
    printf("\nPessoa 1 \nnome: %s, \nidade: %d", person1.name, person1.age);
    printf("\n\nPessoa 2 \nnome: %s, \nidade: %d", person2.name, person2.age);
    printf("\n");
    return 0;
}
