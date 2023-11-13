
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    if (p->prox == NULL)
        return 0;
    celula *lixo = p->prox;
    p->prox = lixo->prox;
    lixo->prox = NULL;
    free(lixo);
    return 1;
}
void remove_elemento(celula *le, int x)
{
    while (le->prox != NULL && le->prox->dado != x)
    {
        le = le->prox;
    }
    if (le->prox->dado == x)
    {
        celula *lixo = le->prox;
        le->prox = lixo->prox;
        lixo->prox = NULL;
        free(lixo);
    }
}

void remove_todos_elementos(celula *le, int x)
{
    while (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            celula *lixo = le->prox;
            le->prox = lixo->prox;
            lixo->prox = NULL;
            free(lixo);
        }
        else
        {
            le = le->prox;
        }
    }
}

/* int main() {
    // Your code here
    return 0;
}

 */
