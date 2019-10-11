#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int number)
{
    for(int i = 2; i <= sqrt(number); ++i)
    {
        if(number % i == 0)
            return false;
    }
    return true;
}

int main()
{
    for(int i = 1; i <= 100; ++i)
    {
        if(isPrime(i))
            printf("%d ", i);
    }
    return 0;
}
