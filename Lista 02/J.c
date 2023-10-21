#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str_aux[101];
int aux = 0;
char *p;
void substr(char *str, char *sub, int len)
{


int main()
{
    char *str = malloc(102 * sizeof(char)), *sub = malloc(101 * sizeof(char)), *p;
    fgets(str, sizeof(str), stdin);
    fgets(sub, sizeof(sub), stdin);
    int tam = substr(str, sub, p, 0);
    printf("%d", tam);
    return 0;
}
