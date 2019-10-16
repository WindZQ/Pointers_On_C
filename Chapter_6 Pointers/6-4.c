#include <stdio.h>
#include <stdbool.h>
#define FALSE false
#define TRUE true
void find_primer(int *numbers, int length)
{
    numbers[0] = FALSE;
    numbers[1] = FALSE;
    int tmp, loc, index = 2;

    while(index < length)
    {
        tmp = index;
        while((tmp += index) < length)
            *(numbers + tmp) = FALSE;
        index++;
    }
}

int main()
{
    int numbers[1000];
    for(int i = 0; i < 1000; ++i)
        numbers[i] = TRUE;
    find_primer(numbers, 1000);
    for(int i = 0; i < 1000; ++i)
    {
        if(numbers[i])
            printf("%-08d", i);
    }
    return 0;
}
