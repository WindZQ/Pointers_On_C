#include <stdio.h>
#include "increment.h"
#include "negate.h"

int main()
{
    int number1 = 10;
    int number2 = 0;
    int number3 = -10;

    printf("%d\n", increment(number1));
    printf("%d\n", negate(number1));
    printf("%d\n", increment(number2));
    printf("%d\n", negate(number2));
    printf("%d\n", increment(number3));
    printf("%d\n", negate(number3));
    return 0;
}
