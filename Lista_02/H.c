#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int max = 81;
void switch_x_y(char *s, int i)
{
    if (s[i] == '\0')
        return;

    if (s[i] == 'x')
    {
        s[i] = 'y';
    }
    switch_x_y(s, i + 1);
}

int main()
{
    char *string = malloc(max * sizeof(char));
    scanf("%s", string);
    switch_x_y(string, 0);
    printf("%s\n", string);
    return 0;
}
