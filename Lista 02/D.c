/*Um truque bem conhecido para descobrir se um inteiro N é um múltiplo de nove é computar a soma S dos seus dígitos. Se
S é um múltiplo de nove, então N também é. Este é um teste recursivo e a profundidade da recursão necessária para obter
a resposta para o número N é chamada o grau-9 de N.
Sua tarefa é, dado um inteiro positivo N, determinar se ele é um múltiplo de nove e, caso ele seja, qual o seu grau-9.
Entrada
A entrada é um arquivo tal que cada linha contém um inteiro positivo. Uma linha contendo o número 0 indica o fim da
entrada. Os números fornecidos na entrada possuem até 1000 dígitos. Saída
Saida
A saída do programa deve indicar, para cada número da entrada, se ele é um múltiplo de nove e, caso ele seja, o seu
grau-9. Veja o exemplo de saída para saber o formato esperado da saída.
Exemplo de Entrada
999999999999999999999
9
9999999999999999999999999999998
0
Exemplo de Saída:
999999999999999999999 is a multiple of 9 and has 9-degree 3.
9 is a multiple of 9 and has 9-degree 1.
9999999999999999999999999999998 is not a multiple of 9. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
const int MAX = 1001;

/* Verifica o grau-9 do numero passado como string
caso base: se o numero for 9, retorna 1
caso recursivo: se a soma dos digitos for multiplo de 9, retorna 1 + o grau-9 da soma dos digitos

Exemplo: 999
primeira chamada: degree_9(999)
9 + 9 + 9 = 27
27 % 9 == 0
degree_9(999) = 1 + degree_9(27)
segunda chamada: degree_9(27)
2 + 7 = 9
9 % 9 == 0
degree_9(27) = 1 + degree_9(9)

terceira chamada: degree_9(9)
degree_9(9) = 1

pilha de chamadas:
degree_9(9) = 1
degree_9(27) = 1 + 1 = 2
degree_9(999) = 1 + 2 = 3
retorna 3 para a main

*/

int sum_digits(char *s)
{
    int sum = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        sum += s[i] - '0';
    }
    return sum;
}

int degree_9(char *s)
{
    if (strlen(s) == 1 && s[0] == '9') // caso base para grau-9
        return 1;

    int sum = sum_digits(s);

    if (sum % 9 != 0)
    {
        return 0;
    }

    char sum_str[MAX];
    sprintf(sum_str, "%d", sum); // converte a soma para string
    return 1 + degree_9(sum_str);
}

int main()
{
    char *number = malloc(MAX * sizeof(char));
    int degree;

    while (1)
    {
        scanf("%s", number);
        if (number[0] == '0')
            break;

        degree = degree_9(number);
        if (degree > 1)
            degree -= 1;

        if (degree > 0)
            printf("%s is a multiple of 9 and has 9-degree %d.\n", number, degree);
        else
            printf("%s is not a multiple of 9.\n", number);
    }
}
