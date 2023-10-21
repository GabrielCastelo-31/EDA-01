#include <stdio.h>
#include <string.h>

int main()
{
    char string[10];
    for (int i = 0; i < 10; i++)
    {
        string[i] = 'a';
        printf("string[%d] = %c\n", i, string[i]);
    }
    printf("%s\n", string);
    printf("%u\n", strlen(string));
    return 0;
}
