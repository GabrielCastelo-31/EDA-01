#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
const int max = 15;

int charToInt(char c)
{
    return c - '0';
}

int sum(char *num, int soma, int i, int j)
{
    if (j == i - 1)
    {
        soma = charToInt(num[j]);
        soma += soma;
        printf("%d\n", soma);
        return soma;
    }
    soma = charToInt(num[j]);
    printf("char da string: %c\n", num[j]);
    printf("char convertido em int: %d\n", soma);
    printf("soma = %d\n", soma);
    return sum(num, soma, i, j + 1);
}
int main()
{
    int result = 0;
    char num[max];
    fgets(num, max, stdin);
    puts(num);
    int i = strlen(num);
    result = sum(num, 0, i, 0);
    printf("r = %d\n", result);
    return 0;
}
