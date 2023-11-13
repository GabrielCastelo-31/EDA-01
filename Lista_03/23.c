#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

typedef struct stack
{
    no *dado;
    struct stack *prox;
} stack;

no *cria_pilha(stack *p)
{
    stack *pilha = malloc(sizeof(stack));
    pilha->prox = NULL;
    return pilha;
}
void empilha(stack *topo, no *node)
{
    stack *pilha = malloc(sizeof(stack));
    pilha->dado = node;
    pilha->prox = topo->prox;
    topo->prox = pilha;
    // return 1;
}
void desempilha(stack *p)
{
    if (p == NULL || p->prox == NULL)
        return 0;

    //*y = p->prox->dado;
    stack *lixo = p->prox;
    p->prox = lixo->prox;
    lixo->prox = NULL;
    free(lixo);
    // return *y;
}
no *topo(stack *p)
{
    if (p == NULL || p->prox == NULL)
        return NULL;
    return p->prox->dado;
}
bool pilha_vazia(stack *p)
{
    if (p->prox == NULL)
        return true;
    return false;
}

void em_ordem(no *raiz)
{
    no *atual = raiz;
    stack *pilha = cria_pilha(pilha);
    while (atual != NULL || !pilha_vazia(pilha))
    {
        if (atual != NULL)
        {
            empilha(pilha, atual);
            atual = atual->esq;
        }
        else
        {
            atual = topo(pilha);
            printf("%d ", atual->dado);
            desempilha(pilha);
            atual = atual->dir;
        }
    }
    printf("\n");
}
