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

stack *cria_pilha()
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
}
void desempilha(stack *p)
{
    if (p == NULL || p->prox == NULL)
        return;


    stack *lixo = p->prox;
    p->prox = lixo->prox;
    lixo->prox = NULL;
    free(lixo);

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

void pos_ordem(no *raiz)
{
    no *atual = raiz;
    stack *pilha = cria_pilha();
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
int main() {
    // Exemplo de utilização
    no *raiz = malloc(sizeof(no));
    raiz->dado = 1;
    raiz->esq = malloc(sizeof(no));
    raiz->esq->dado = 2;
    raiz->esq->esq = raiz->esq->dir = NULL;
    raiz->dir = malloc(sizeof(no));
    raiz->dir->dado = 3;
    raiz->dir->esq = raiz->dir->dir = NULL;

    pos_ordem(raiz);

    return 0;
}
