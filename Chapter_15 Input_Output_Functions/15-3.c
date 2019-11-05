#include <stdio.h>
#define N 81
int main()
{
    char buf[N];
    while(gets(buf))
    {
        int len = sizeof(buf);
        if(buf[len - 1] !='\n')
            puts(buf);
    }
    return 0;
}
