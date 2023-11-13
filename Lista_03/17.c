#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int dado;
    struct stack *prox;
} stack;

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

/* int main()
{
    // your code here
    return 0;
} */
