#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int identity_matrix(int **a, int number)
{
    int i, j;
    for(i = 0; i < number; ++i)
    {
        if(*(a[i] + i) == 1)
        {
            for(j = 0; j < number; ++j)
            {
                if(j != i && *(a[i] + j) != 0)
                    return 0;
                else
                    continue;
            }
        }
    }
    if(i == number)
        return 1;
    else
        return 0;
}

int main()
{
    int i, j, **a;
    int number;
    printf("Please input a number:");
    scanf("%d", &number);
    if((a = (int **)malloc(sizeof(int *) * number)) == NULL)
    {
        printf("error = %d\n", errno);
        printf("%s\n", strerror(errno));
    }
    for(j = 0; j < number; ++j)
    {
        if((a[j] = (int *)malloc(sizeof(int) * number)) == NULL)
        {
            printf("error = %d\n", errno);
            printf("%s\n", strerror(errno));
        }
    }
    printf("Please input array number:\n");
    for(i = 0; i< number; ++i)
    {
        for(j = 0; j < number; ++j)
            scanf("%d", &a[i][j]);
    }
    printf("The array number is:\n");
    for(i = 0; i < number; ++i)
    {
        for(j = 0; j < number; ++j)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("result is %d\n", identity_matrix(a, number));
    return 0;
}
