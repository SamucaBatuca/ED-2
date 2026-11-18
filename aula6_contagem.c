/* e1_contagem.c — EXERCICIO 1 (esqueleto)
 * Estruturas de Dados II (CMP2109) — Encontro 06
 *
 * OBJETIVO
 *   Para CADA um dos tres trechos abaixo:
 *     (a) no papel, monte a tabela custo x frequencia e deduza T(n);
 *     (b) instrumente o codigo com um contador da operacao dominante;
 *     (c) execute para n = 10, 100 e 1000 e compare medicao com previsao.
 *
 *   Entregue o codigo e um relatorio.txt com as tres deducoes e a tabela
 *   de conferencia. Se medicao e previsao divergirem, EXPLIQUE a causa —
 *   e o item que mais vale nota.
 *
 * DICA: a operacao dominante sugerida esta indicada em cada trecho.
 *
 * COMPILAR  gcc -std=c11 -Wall -Wextra -g e1_contagem.c -o e1
 */
#include <stdio.h>
#include <stdlib.h>

static long ops = 0;

/* TRECHO A — operacao dominante: a soma  s += v[i]
 * T(n) = ?
 */
static long trecho_a(const int *v, int n)
{
    long s = 0;
    for (int i = 0; i < n; i++)
        s += v[i];              /* TODO: contar */
    return s;
}

/* TRECHO B — operacao dominante: a comparacao  v[i] > v[j]
 * Atencao ao limite do laco interno.
 * T(n) = ?
 */
static long trecho_b(const int *v, int n)
{
    long maiores = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j])    /* TODO: contar a COMPARACAO, nao o if */
                maiores++;
    return maiores;
}

/* TRECHO C — operacao dominante: o corpo do laco interno
 * CUIDADO: o laco interno nao vai ate n. Quantas vezes ele executa?
 * T(n) = ?
 */
static long trecho_c(int n)
{
    long t = 0;
    for (int i = 1; i < n; i = i * 2)
        for (int j = 0; j < n; j++)
            t++;                /* TODO: contar */
    return t;
}

int main(void)
{
    int tamanhos[] = {10, 100, 1000};

    for (size_t k = 0; k < sizeof(tamanhos) / sizeof(*tamanhos); k++) {
        int n = tamanhos[k];
        int *v = malloc((size_t) n * sizeof *v);
        if (v == NULL) return 1;
        for (int i = 0; i < n; i++)
            v[i] = rand() % 1000;

        /* TODO: zerar ops, chamar cada trecho e imprimir
                 medicao ao lado da previsao da sua formula */
        ops = 0; trecho_a(v, n);
        printf("ops = %ld (substitua por uma tabela de conferencia)\n", trecho_a(v, n));
        /*ops = 0; trecho_b(v, n);
        printf("ops = %ld (substitua por uma tabela de conferencia)\n", ops);
        ops = 0; trecho_c(n);
        printf("ops = %ld (substitua por uma tabela de conferencia)\n", ops);
        */
        free(v);
        v = NULL;
    }

    printf("ops = %ld (substitua por uma tabela de conferencia)\n", ops);
    return 0;
}
