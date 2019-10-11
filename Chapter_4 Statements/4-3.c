#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Please input three number:");
    scanf("%d%d%d", &a, &b, &c);
    if(a + b > c && a - b < c)
    {
        if(a == b == c)
            printf("等边三角形\n");
        else if(a == b || b == c || a == c)
            printf("等腰三角形\n");
        else
            printf("不等边三角形\n");
    }
    else
        printf("无法构成三角形\n");
    return 0;
}
