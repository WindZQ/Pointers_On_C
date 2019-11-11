#include <stdio.h>

char * convert(int m, int n)
{
    char table[16] = {0};

    if(m < 0)
        m *= (-1);
    for(int i = 0; i < 16; ++i)
    {
        if(i < 10)
            table[i] = i + '0';
        else
            table[i] = i - 10 + 'A';
    }
    char *res;
    while(m)
    {
        int temp = m % n;
        char t= table[temp];
        res += t;
        m /= n;
    }
    return res;
}

int main(int argc, char **argv)
{
    if(argc < 2)
        printf("Error!\n");
    int m, n;
    while(scanf("%d%d", argv[0], argv[1]) == 2)
    {
        char *res = convert(m, n);
        if(m < 0)
            printf("-\n");
        printf("%s", res);
    }
    return 0;
}
