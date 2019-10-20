#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
    register int *m1p;
    register int *m2p;
    register int k;
    int row, column;
    int i, j;
    printf("The matrix m1 is:\n");
    for(i = 0; i < x * y; ++i)
    {
        printf("%d\t", m1[i]);
        if((i + 1) % y == 0)
            printf("\n");
    }
    printf("The matrix m2 is:\n");
    for(i = 0; i < x * z; ++i)
    {
        printf("%d\t", m2[i]);
        if((i + 1) % z == 0)
            printf("\n");
    }

    for(row = 0; row < x; ++row)
    {
        for(column = 0; column < z; ++column)
        {
            m1p = m1 + row * y;
            m2p = m2 + column;
            *r = 0;
            for(k = 0; k < y; ++k)
            {
                *r += (*m1p) * (*m2p);
                m1p += 1;
                m2p += z;
            }
            printf("%d\t", *r);
            r++;
        }
        printf("\n");
    }

    printf("The muliply matrix is:\n");
    for(row = 0; row < x * z; ++row)
    {
        printf("%d\t", r[row]);
        if((row + 1) % z == 0)
            printf("\n");
    }
}

int main()
{
    int x, y, z, *m1, *m2;
    register int *r;
    int i, j;
    printf("Please input x,y and z:\n");
    scanf("%d%d%d",&x,&y,&z);
    assert(x > 0 && y > 0 && z > 0);
    if((m1 = (int *)malloc(sizeof(int) * (x * y))) == NULL)
    {
        printf("errno = %d\n",errno);
        printf("%s\n",strerror(errno));
    }
    if((m2 = (int *)malloc(sizeof(int) * (y * z))) == NULL)
    {
        printf("errno = %d\n",errno);
        printf("%s\n",strerror(errno));
    }

    if((r = (int *)malloc(sizeof(int) * (x * z))) == NULL)
    {
        printf("errno = %d\n",errno);
        printf("%s\n",strerror(errno));
    }
    for(i = 0; i < x * z; i++)
        r[i] = 0;
    printf("Please input matrix m1:\n");
    for(i = 0;i < ( x * y); i++)
    {
        scanf("%d",&m1[i]);
    }
    printf("Please input matrix m2:\n");
    for(j = 0; j < (y * z); j++)
    {
        scanf("%d",&m2[j]);
    }
    printf("The matrix m1 is: \n");
    for(i = 0; i < x * y; i++)
    {
        printf("%d\t",m1[i]);
        if((i + 1) % y == 0)
            printf("\n");
    }
    printf("The matrix m2 is: \n");
    for(i = 0; i < y * z; i++)
    {
        printf("%d\t",m2[i]);
        if((i + 1) % z == 0)
            printf("\n");
    }
    printf("The result of multiply matrix is :\n");
    matrix_multiply(m1, m2, r, x, y, z);
    return 0;
}
