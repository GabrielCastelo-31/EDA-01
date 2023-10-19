#include <stdio.h>
#include <string.h>

const int max = 101;
const char x = 'x';

void move_x(char *str, int len, int i, int j)
{
    if (i == len)
    {
        // str[len] = '\0';
        return;
    }

    if (str[i] == x)
    {
        char temp = str[i];
        memmove(&str[i], &str[i + 1], sizeof(char) * (len - i - 1));
        str[len - 1] = temp;
        move_x(str, len - 1, i, j); // Adjusted the parameters
    }
    else
    {
        move_x(str, len, i + 1, j);
    }
}

int main()
{
    char str[max];
    fgets(str, max, stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    move_x(str, len, 0, 0);
    printf("%s\n", str);
    return 0;
}
