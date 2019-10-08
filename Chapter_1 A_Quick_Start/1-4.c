#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

int main()
{
    char s[N], str[N];
    int s_length = -1, str_length = -1;
    while(gets(str) != NULL)
    {
        str_length = strlen(str);
        if(str_length > s_length)
        {
            strcpy(s, str);
            s_length = str_length;
        }
    }
    if(s_length > 0)
        puts(s);
    return 0;
}
