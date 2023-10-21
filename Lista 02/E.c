#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
const long int MAX = 15;

int sum_digits(char *s, int len, int sum)
{
    int i = len - 1; // posiçao correta na string

    if (i == 0)
        return s[0] - '0';

    sum = s[i] - '0';
    len--;
    return sum + sum_digits(s, len, sum);
}
int main()
{
    char number[MAX];
    scanf("%s", number);
    int sum = sum_digits(number, strlen(number), 0);
    printf("%d\n", sum);
    return 0;
}
