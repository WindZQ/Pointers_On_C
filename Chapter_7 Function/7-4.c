#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int max_list(int first, ...)
{
    va_list arg;
    int max;
    if(first < 0)
        return 0;
    va_start(arg, first);
    max = first;
    int temp = va_arg(arg, int);
    while(temp >= 0)
    {
        if(temp > max)
            max = temp;
        temp = va_arg(arg, int);
    }
    va_end(arg);
    return max;
}

int main()
{
    int max = max_list(2, 4, 5, 6, 7, 1, -1);
    printf("%d\n", max);

    max = max_list(-1);
    printf("%d\n", max);

    max = max_list(2, -10);
    printf("%d\n", max);

    return 0;
}
