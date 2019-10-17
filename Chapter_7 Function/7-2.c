#include <stdio.h>

int gcd(int m, int n)
{
    if(n == 0)
        return m;
    else
        return gcd(n, m % n);
}

int main()
{
    int m, n, result;
    printf("Please input the number(m > n):");
    scanf("%d%d", &m, &n);
    result = gcd(m, n);
    printf("The result: %d\n", result);
    return 0;
}
