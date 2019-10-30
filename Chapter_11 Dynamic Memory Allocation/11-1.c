#include <stdio.h>
#include <stdlib.h>

void *myalloc(unsigned long int length, unsigned long int typesize)
{
    int *ptr;
    int index = 0;
    int totalen = length * typesize;
    if(length >= 0 && typesize >= 0)
    {
        ptr = (int *)malloc(totalen);
        if(ptr != NULL)
        {
            for(index = 0; index < totalen; ++index)
                *(ptr + index) = 0;
            return ptr;
        }
        return NULL;
    }
    return NULL;
}

int main()
{
    int *ptr = myalloc(10, sizeof(int));
    int i;
    for(i = 0; i < 10; ++i)
        printf("%d\t", *(ptr + i));
    for(i = 0; i < 10; ++i)
    {
        if(ptr != NULL)
            free(ptr);
    }
    return 0;
}
