#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hello();

int main()
{
    hello();
    return 0;
}

void hello()
{
    char name[50];
    printf("Digite o seu nome: ");
    scanf("%49[^\n]", name); // Lê até encontrar uma nova linha

    char message[100];

    // Aloca memória para a mensagem, incluindo espaço para o nome digitado
    if (sprintf(message, "Olá, %s\n", name) < 0)
    {
        printf("Erro ao formatar a mensagem.\n");
        return;
    }

    puts(message);
}
