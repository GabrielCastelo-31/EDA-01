#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct pilha
{
    int *dados;
    int N, topo;
} pilha;

int redimensiona(pilha *p)
{
    int N = 2 * p->N;
    p->N = N;

    int *dados = malloc(sizeof(int) * N);

    for (int i = 0; i < p->topo; i++)
        dados[i] = p->dados[i];
    free(p->dados);
    p->dados = dados;
}

int empilha(pilha *p, int x)
{
    if ((p->topo == p->N) || p == NULL)
        redimensiona(p);

    p->dados[p->topo] = x;
    p->topo++;
    return 1;
}
