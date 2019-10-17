#include <stdio.h>

int hermite(int n, int x)
{
    if(n <= 0)
        return 1;
    if(n == 1)
        return 2 * x;
    return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}

int main()
{
    int x, n, result;
    printf("Please input the number:");
    scanf("%d%d", &x, &n);
    result = hermite(x, n);
    printf("The result:%d\n", result);
    return 0;
}
