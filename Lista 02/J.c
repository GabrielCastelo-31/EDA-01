#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Sua tarefa nesse exercício é, dadas duas cadeias de caracteres str e sub, determinar recursivamente qual a maior subcadeia
de str que começa e termina por sub.
Atenção: Você não pode usar laços na sua solução.
Entrada
A entrada é composta por duas linhas. A primeira linha contém str, que pode ter tamanho entre zero e 100, e a segunda
linha contém sub, que pode ter tamanho entre 1 e 100.
Saída
A saída deve conter uma única linha com o tamanho da maior subcadeia de str que começa e termina por sub.
 */
int len_sub = 0;
// Encontra a maior subcadeia de str que começa e termina por sub
int find_string(char *str, char *sub, int len)
{
    char *p = strstr(str, sub);
    if (p == NULL)
        return 0;
    else
    {
        len_sub = strlen(sub);
        return len_sub + find_string(p + len_sub, sub, len_sub);
    }
}

int main()
{
    char *str = malloc(102 * sizeof(char)), *sub = malloc(101 * sizeof(char));
    fgets(str, 102, stdin);
    fgets(sub, 101, stdin);
    str[strlen(str) - 1] = '\0';
    sub[strlen(sub) - 1] = '\0';
    if (strcmp(str, sub) == 0)
    {
        printf("%d", strlen(str));
    }
    else
    {
        printf("%d", find_string(str, sub, strlen(sub)));
    }
    return 0;
}
