#include <stdio.h>

int noventa_e_um(int n)
{
    // int result;
    if (n >= 101)
        return n - 10;
    else
        return noventa_e_um(noventa_e_um(n + 11));
}

int main()
{
    int n = 1;
    int result;
    while (n != 0)
    {
        scanf("%d", &n);
        if (n != 0)
        {
            result = noventa_e_um(n);
            printf("f91(%d) = %d\n", n, result);
        }
    }
}
