#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Address {
    char number[100];
    char zipcode[100];
    char street[100];
    char neighborhood[100];
    char city[100];
};

struct Person {
    char name[100];
    int age;
    struct Address address;
};

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    printf("---Cadastro de clientes---\n");
    struct Person *clients = NULL;
    int numberOfClients = 0;

    for (;;) {
        char wantToContinue;

        char name[100];
        int age;
        char number[100];
        char zipcode[100];
        char street[100];
        char neighborhood[100];
        char city[100];

        printf("Nome: ");
        scanf("%99[^\n]", name);
        clearBuffer();

        printf("Idade: ");
        scanf("%d", &age);
        clearBuffer();

        printf("Rua: ");
        scanf("%99[^\n]", street);
        clearBuffer();

        printf("Número: ");
        scanf("%99[^\n]", number);
        clearBuffer();

        printf("Cep: ");
        scanf("%99[^\n]", zipcode);
        clearBuffer();

        printf("Bairro: ");
        scanf("%99[^\n]", neighborhood);
        clearBuffer();

        printf("Cidade: ");
        scanf("%99[^\n]", city);
        clearBuffer();

        printf("Deseja continuar adicionando? (S/N): ");
        scanf(" %c", &wantToContinue);
        clearBuffer();

        wantToContinue = toupper(wantToContinue);

        clients = realloc(clients, (numberOfClients + 1) * sizeof(struct Person));
        if (clients == NULL) {
            printf("<Erro> Não foi possível alocar memória!");
            return 1;
        }

        strcpy(clients[numberOfClients].name, name);
        clients[numberOfClients].age = age;
        strcpy(clients[numberOfClients].address.street, street);
        strcpy(clients[numberOfClients].address.number, number);
        strcpy(clients[numberOfClients].address.zipcode, zipcode);
        strcpy(clients[numberOfClients].address.neighborhood, neighborhood);
        strcpy(clients[numberOfClients].address.city, city);

        numberOfClients++;

        if (wantToContinue == 'N') {
            break;
        } else if (wantToContinue != 'S') {
            printf("<Erro> Opção inválida\n");
            break;
        }
    }

    if (numberOfClients > 0) {
        printf("Clientes cadastrados:\n");
        for (int i = 0; i < numberOfClients; i++) {
            printf("\n");
            printf("Nome: %s\n", clients[i].name);
            printf("Idade: %d\n", clients[i].age);
            printf("Rua: %s\n", clients[i].address.street);
            printf("Número: %s\n", clients[i].address.number);
            printf("Cep: %s\n", clients[i].address.zipcode);
            printf("Bairro: %s\n", clients[i].address.neighborhood);
            printf("Cidade: %s\n", clients[i].address.city);
        }
    } else {
        printf("Nenhum cliente cadastrado.\n");
    }

    free(clients);

    return 0;
}
