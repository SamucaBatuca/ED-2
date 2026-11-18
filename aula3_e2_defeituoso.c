/* e2_defeituoso.c — EXERCICIO 2
 * Estruturas de Dados II (CMP2109) — Aula 03
 *
 * OBJETIVO
 *   Este programa EXECUTA ate o fim sem falhar, mas contem TRES erros de
 *   memoria de tipos diferentes. O compilador denuncia apenas UM deles: os
 *   outros dois so aparecem sob o Valgrind. Sua tarefa:
 *
 *   1. Execute sob o Valgrind e copie o diagnostico de cada erro.
 *   2. Para cada um, indique: (a) a linha; (b) o tipo do erro
 *      (vazamento / leitura ou escrita invalida / uso apos liberacao /
 *      liberacao dupla / acesso fora dos limites); (c) por que ocorre.
 *   3. Corrija os tres, mantendo a saida funcional do programa.
 *   4. Entregue o arquivo corrigido e um relatorio.txt com os itens 1 e 2.
 *
 * COMPILAR   gcc -std=c11 -Wall -Wextra -g e2_defeituoso.c -o e2
 * VERIFICAR  valgrind --leak-check=full --track-origins=yes ./e2
 *
 * ATENCAO: nao apague nenhuma funcionalidade. A saida corrigida deve ser:
 *   dobro: 2 4 6 8 10
 *   soma dos rotulos: 15
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Devolve um vetor com o dobro de cada elemento de v. */
static int *dobra(const int *v, size_t n)
{
    int *saida = malloc(n * sizeof *saida);
    if (saida == NULL) return NULL;
    for (size_t i = 0; i < n; i++)          // correção A: "i<n"
        saida[i] = 2 * v[i];
    return saida;
}

/* Soma os valores de um vetor e o libera. */
static int soma_e_libera(int *v, size_t n)
{
    int s = 0;
    for (size_t i = 0; i < n; i++)
        s += v[i];
    free(v);                                   // correção B: free(v) antes do return
    return s;
}

int main(void)
{
    int base[5] = {1, 2, 3, 4, 5};

    int *d = dobra(base, 5);
    if (d == NULL) return 1;

    printf("dobro:");
    for (size_t i = 0; i < 5; i++)
        printf(" %d", d[i]);
    putchar('\n');

    char *rotulo = malloc(32);
    if (rotulo == NULL) { free(d); return 1; }
    strcpy(rotulo, "vetor de rotulos");

    int *copia = malloc(5 * sizeof *copia);
    if (copia == NULL) { free(d); free(rotulo); return 1; }
    memcpy(copia, base, 5 * sizeof *copia);

    printf("soma dos rotulos: %d\n", soma_e_libera(copia, 5));

    free(d);
    free(rotulo);                              // correção C: liberar 'rotulo'
    return 0;
}
