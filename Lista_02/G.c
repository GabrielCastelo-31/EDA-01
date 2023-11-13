#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int max = 201;

int conta_par(char *s, int i, int pares)
{
    if (s[i] == '\0')
        return pares;
    if (s[i] == s[i + 2])
        pares++;
    return conta_par(s, i + 1, pares);
}
int main()
{
    char *string = malloc(max * sizeof(char));
    fgets(string, max, stdin);
    int num_pares = conta_par(string, 0, 0);
    printf("%d\n", num_pares);
    return 0;
}
