#include <stdio.h>
#include <string.h>

char *deblank(char string[])
{
    char *str = string;
    for(int i = 0; string[i] != '\0'; ++i)
    {
        if(string[i] != ' ')
            *str++ = string[i];
        if((string[i] == ' ') && !(string[i + 1] == ' '))
            *str++ = string[i];
    }
    *str = '\0';
    return string;
}

void deblank1(char string[])
{
    int i, j, k, blank = 0, str = 0;
    int sum1, sum2;
    int m, n = 0;
    sum1 = strlen(string);
    for(m = 0; string[m] != '\0'; ++m)
    {
        if(string[m] == ' ' && string[m + 1] != ' ')
            n++;
    }
    for(j = 0; j < sum1; ++j)
    {
        if(string[j] == ' ')
            blank++;
    }
    for(i = 0; string[i] != '\0';)
    {
        if(string[i] == ' ')
        {
            for(j = i; string[j] == ' '; ++j)
                str++;
        }
        if(string[i] != ' ')
            ++i;
        if(str != 0)
        {
            for(k = j; k < sum1; ++k)
                string[k - str + 1] = string[k];
            i = j - str + 1;
        }
        if(str == sum1)
        {
            string[0] = ' ';
            string[1] = '\0';
        }
        str = 0;
    }
    sum2 = sum1 - blank + n;
    string[sum2] = '\0';
}

int main()
{
    char a[100] = {0}, b[100] = {0}, *p = NULL;
    gets(a);
    strcpy(b, a);
    deblank1(b);
    puts(b);
    p = deblank(a);
    puts(p);
    return 0;
}
