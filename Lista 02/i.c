#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int max = 501;

void imprime_ao_contrario(char *s)
{
    if (*s != '\0')
    {
        imprime_ao_contrario(s + 1);
        printf("%c", *s);
    }
    else
        return;
}
int main()
{
    char *s = malloc(max * sizeof(char));
    scanf("%s", s);
    imprime_ao_contrario(s);
    printf("\n");
    return 0;
}
