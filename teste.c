#include <stdio.h>
#include <string.h>

int maiorSubstringRecursiva(char *str, char *sub, int i, int j, int max)
{

int main()
{
    char str[101], sub[101];
    fgets(str, sizeof(str), stdin);
    fgets(sub, sizeof(sub), stdin);

    str[strcspn(str, "\n")] = '\0';
    sub[strcspn(sub, "\n")] = '\0';

    int tamanhoMaiorSubstring = maiorSubstringRecursiva(str, sub, strlen(str), strlen(sub), 0);
    printf("%d\n", tamanhoMaiorSubstring);

    return 0;
}
