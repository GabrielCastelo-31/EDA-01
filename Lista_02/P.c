#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x)
{
    celula *p = malloc(sizeof(celula));
    p->dado = x;
    p->prox = le->prox;
    le->prox = p;
}

void insere_antes(celula *le, int x, int y)
{
    while (le->prox != NULL && le->prox->dado != y)
    {
        le = le->prox;
    }
    celula *p = malloc(sizeof(celula));
    p->dado = x;
    p->prox = le->prox;
    le->prox = p;
}
/* int main() {
    // Your code here
    return 0;
}
 */
