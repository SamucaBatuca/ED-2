#include <stdio.h>
#include <stdlib.h>

int capacidade = 4;
int tamanho = 0;

void dobra_vetor(int *vetor, int valor) {
    if (tamanho == capacidade) {
        int nova_capacidade = capacidade * 2;
        int *aux = realloc(vetor, nova_capacidade * sizeof(int));

        if (aux == NULL) {
            printf("Erro ao realocar memória.\n");
            free(vetor);
            return;
        }

        vetor = aux;
        capacidade = nova_capacidade;
    }

    vetor[tamanho++] = valor;
}


int main(void) {
    

    int *vetor = malloc(capacidade * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória inicial.\n");
        return 1;
    }

    int valor;
    while (scanf("%d", &valor) == 1) {
        dobra_vetor(vetor, valor);
    }

    printf("Valores lidos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    vetor = NULL;

    return 0;
}