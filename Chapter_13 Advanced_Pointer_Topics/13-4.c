#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arry[4] = {6, 2, 3, 1};

int cmp(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort(void *base, unsigned int n, unsigned int width, int (*comp)(void *a, void *b))
{
    char *p = (char *)base;
    char *te = (char *)malloc(width);
    char *ptr;
    char *pn;
    const char *cp = p + (n - 1) * width;
    for(; p < cp; p += width)
    {
        for(pn = p + width; pn <= cp; pn += width)
        {
            ptr = p;
            printf("test:%d\n", (*comp)(ptr, pn));
            if((*comp)(ptr, pn) > 0)
                ptr = pn;
            if(ptr != p)
            {
                memcpy(te, p, width);
                memmove(p, ptr, width);
                memmove(ptr, te, width);
            }
        }
    }
    free(te);
}

int main()
{
    int i;
    sort(arry, 4, sizeof(arry[1]), cmp);
    for(i = 0; i < 4; ++i)
        printf("%d\t", arry[i]);
    printf("\n");
    return 0;
}
