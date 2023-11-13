#include <stdio.h>
long int F[80];
long int fibonacci(int n)
{
    if (n == 2 || n == 1)
        return 1;

    if (F[n] != 0)
        return F[n];
    F[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return F[n];
}
/* int main()
{
    int n;
    scanf("%d", &n);
    printf("%ld\n", fibonacci(n));
    return 0;
}
 */
