#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define lesseq(A, B) ((A) <= (B))
#define swap(A, B) \
    {              \
        int t = A; \
        A = B;     \
        B = t;     \
    }
#define cmpexch(A, B)     \
    {                     \
        if (lesseq(B, A)) \
            swap(A, B);   \
    }

typedef struct dict
{
    int key;
    char *value;
} dict;
void insertionSort(int *v, int l, int r)
{
    // InsertionSort otimizado
    for (int i = r; i > l; i--)
    {
        cmpexch(v[i - 1], v[i]);
    }
    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        int tmp = v[j];
        while (lesseq(tmp, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
    }
}

void merge(int *v, int l, int r1, int r2)
{
    int *v2 = malloc((r2 - l + 1) * sizeof(int));
    int i = l, j = r1 + 1, k = 0;
    while (i <= r1 && j <= r2)
    {
        if lesseq (v[i], v[j])
            v2[k++] = v[i++];
        else
            v[k++] = v[j++];
    }
    while (i <= r1)
    {
        v2[k++] = v[i++];
    }
    while (j <= r2)
    {
        v2[k++] = v[j++];
    }
    k = 0;

    for (int i = l; i <= r2; i++)
    {
        v[i] = v2[k++];
    }
    free(v2);
}

void merge_sort(int *v, int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    merge(v, l, m, r);
}
int main()
{
    int n;
    scanf("%d", &n);
    dict *d = malloc(n * sizeof(dict));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &d[i].key, d[i].value);
    }
}