#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void ultrapassa_minimamente(int *numbers, int max, int sum, int len)
{
    int *v = calloc(len, sizeof(int));
    int len_v = 0;
    for (int i = 0; i <= len; i++)
    {
        sum += numbers[i];
        /*   printf("Soma:%d\n", sum);
          printf("max:%d\n", max); */
        if (sum > max)
        {
            v[len_v] = numbers[i];
            /* printf("Numero da lista para imprimir após sum>max:%d\n", v[len_v]); */
            len_v++;
            sum = 0;
        }
    }
    for (int i = len_v - 1; i >= 0; i--)
    {
        printf("%d\n", v[i]);
    }
}
int main()
{
    int *v = calloc(4096, sizeof(int));
    int x = 0;
    int i = 0;
    int max = 0;
    while (true)
    {
        scanf(" %d", &x);
        if (x != 0)
        {
            v[i] = x;
            /* printf("V[%d]:%d\n", i, v[i]); */
            i++;
        }
        else
        {
            /* printf("X:%d\n", x); */
            break;
        }
    }
    scanf("%d", &max);

    /* printf("Max:%d\n", max); */
    ultrapassa_minimamente(v, max, 0, i);
    return 0;
}
