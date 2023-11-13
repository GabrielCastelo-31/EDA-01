#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    while (l1->prox != NULL && l2->prox != NULL)
    {
        if (l1->prox->dado <= l2->prox->dado)
        {
            l3->prox = l1->prox;
            l1->prox = l1->prox->prox;
        }
        else
        {
            l3->prox = l2->prox;
            l2->prox = l2->prox->prox;
        }
        l3 = l3->prox;
    }
    if (l1->prox != NULL)
    {
        while (l1->prox != NULL)
        {
            l3->prox = l1->prox;
            l1->prox = l1->prox->prox;
            l3 = l3->prox;
        }
    }
    if (l2->prox != NULL)
    {
        while (l2->prox != NULL)
        {
            l3->prox = l2->prox;
            l2->prox = l2->prox->prox;
            l3 = l3->prox;
        }
    }
    l3->prox = NULL;
}

/* int main() {
    // Your code here
    return 0;
}
 */
