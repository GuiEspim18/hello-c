#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definindo a estrutura do perceptron
typedef struct {
    double *pesos;
    double taxa_aprendizado;
    int num_entradas;
} Perceptron;

// Função de inicialização do perceptron
void inicializarPerceptron(Perceptron *perceptron, int num_entradas, double taxa_aprendizado) {
    perceptron->num_entradas = num_entradas;
    perceptron->taxa_aprendizado = taxa_aprendizado;

    // Alocar espaço para os pesos, incluindo o peso do viés
    perceptron->pesos = (double *)malloc((num_entradas + 1) * sizeof(double));

    // Inicializar pesos aleatoriamente
    for (int i = 0; i <= num_entradas; ++i) {
        perceptron->pesos[i] = ((double)rand() / RAND_MAX) * 2 - 1;  // Valores entre -1 e 1
    }
}

// Função de previsão do perceptron
int prever(Perceptron *perceptron, double *entradas) {
    double soma = perceptron->pesos[0];  // Peso do viés

    // Calcular a soma ponderada das entradas
    for (int i = 0; i < perceptron->num_entradas; ++i) {
        soma += entradas[i] * perceptron->pesos[i + 1];
    }

    // Aplicar a função de ativação (degrau)
    return (soma >= 0) ? 1 : 0;
}

// Função de treinamento do perceptron para a operação lógica AND
void treinarAND(Perceptron *perceptron) {
    double entradas[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    int saidas_desejadas[4] = {0, 0, 0, 1};

    int epocas = 0;
    int erro;

    do {
        erro = 0;

        for (int i = 0; i < 4; ++i) {
            int previsao = prever(perceptron, entradas[i]);
            int erro_local = saidas_desejadas[i] - previsao;

            if (erro_local != 0) {
                erro += 1;

                // Atualizar pesos
                perceptron->pesos[0] += perceptron->taxa_aprendizado * erro_local;

                for (int j = 0; j < perceptron->num_entradas; ++j) {
                    perceptron->pesos[j + 1] += perceptron->taxa_aprendizado * erro_local * entradas[i][j];
                }
            }
        }

        epocas++;

    } while (erro > 0 && epocas < 10000);  // Limitar o número de épocas para evitar loops infinitos

    printf("Treinamento concluído em %d épocas\n", epocas);
}

// Função de liberação de memória do perceptron
void liberarPerceptron(Perceptron *perceptron) {
    free(perceptron->pesos);
}

int main() {
    // Inicializar o perceptron para operação lógica AND com duas entradas
    Perceptron perceptron;
    inicializarPerceptron(&perceptron, 2, 0.1);

    // Treinar o perceptron
    treinarAND(&perceptron);

    // Testar o perceptron treinado
    printf("Teste:\n");
    printf("0 AND 0 = %d\n", prever(&perceptron, (double[]){0, 0}));
    printf("0 AND 1 = %d\n", prever(&perceptron, (double[]){0, 1}));
    printf("1 AND 0 = %d\n", prever(&perceptron, (double[]){1, 0}));
    printf("1 AND 1 = %d\n", prever(&perceptron, (double[]){1, 1}));

    // Liberar memória alocada pelo perceptron
    liberarPerceptron(&perceptron);

    return 0;
}
