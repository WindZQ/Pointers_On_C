#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define N     3

int identity_matrix(int **a)
{
    int i, j;
    for(i = 0;i < N; ++i)
    {
        if(*(a[i] + i) == 1)
        {
            for(j = 0; j < N; ++j)
            {
                if(j != 1 && *(a[i] + j) != 0)
                    return 0;
                else
                    continue;
            }
        }
    }
    if(i == N)
        return 1;
    else
        return 0;
}

int main()
{
    int i, j, **a;

    if((a = (int **)malloc(sizeof(int *) * N)) == NULL)
    {
        printf("error = %d\n",errno);
        printf("%s\n",strerror(errno));
    }

    for(j = 0; j < N; ++j)
    {

        if((a[j] = (int *)malloc(sizeof(int) * N))==NULL)
        {
            printf("error = %d\n",errno);
            printf("%s\n",strerror(errno));
        }
    }
    printf("Please input array number:\n");
    for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
            scanf("%d",&a[i][j]);
    printf("The array number is :\n");
    for(i = 0;i < N; ++i)
    {
        for(j = 0; j < N; ++j)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("The result is %d\n",identity_matrix(a));
    return 0;
}
