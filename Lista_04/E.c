#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const int MAX = 5123;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define lessEq(A, B) (key(A) <= key(B))
#define exch(A, B)  \
    {               \
        item t = A; \
        A = B;      \
        B = t;      \
    }
#define cmpexch(A, B) \
    if (less(A, B))   \
    exch(A, B)

void ordena(item *vetor, item l, item r) // Recursivo
{
    int i = l;
    if (i == r)
        return;
}
