#include <stdio.h>
#include <string.h>

char *my_strnchr(char const *str, int ch, int which)
{
    int i;
    char *p = NULL;
    p = str;
    for(i = 0; i < which; ++i)
    {
        if(i != 0)
            p++;
        p = strchr(p, ch);
    }
    return p;
}

int main()
{
    int i;
    char str[] = "Hello world!";
    int chr = '1';
    int which = 2;
    char *find = my_strnchr(str, chr, which);
    for(i = -1; i < 2; ++i)
        printf("%c\t", *(find + i));
    printf("\n");
    return 0;
}
