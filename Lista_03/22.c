#include <stdlib.h>

typedef struct pilha
{
    int *dados;
    int N, topo;
} pilha;

int desempilha(pilha *p, int *y)
{
    if (p->topo <= 0)
        return 0;
    *y = p->dados[(p->topo) - 1];
    p->topo--;
    return 1;
}

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
