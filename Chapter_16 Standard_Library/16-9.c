#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(void const *birth, void const *birth1)
{
    return *(int *)(birth) - *(int *)(birth1);
}

int count_same(int *array, int len)
{
    while(len > 0)
    {
        if(array[len] == array[len - 1])
            return 1;
        len--;
    }
    return 0;
}

int main(void)
{
    int times = 0, pepleCount = 0, sameCount = 0;
    int randBirthday[30];
    srand((unsigned int)time(0));

    while(times < 100000)
    {
        pepleCount = 29;
        while(pepleCount >= 0)
        {
            randBirthday[pepleCount] = rand() % 365;
            pepleCount--;
        }
        qsort(randBirthday, 30, sizeof(int), compare);
        sameCount += count_same(randBirthday, 29);
        times++;
    }
    printf("%f", (float)(sameCount) / 100000);
    return 0;
}
