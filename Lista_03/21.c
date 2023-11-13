#include <stdlib.h>

typedef struct stack
{
    int dado;
    struct stack *prox;
} stack;

int empilha(stack *p, int x)
{
    /*  if (p == NULL || p->prox == NULL)
         return 0; */

    stack *nova = malloc(sizeof(stack));
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
    return 1;
}
int desempilha(stack *p, int *y)
{
    if (p == NULL || p->prox == NULL)
        return 0;

    *y = p->prox->dado;
    stack *lixo = p->prox;
    p->prox = lixo->prox;
    lixo->prox = NULL;
    free(lixo);
    return 1;
}
