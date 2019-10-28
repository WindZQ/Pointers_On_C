#include <stdio.h>
#include <string.h>
#include <ctype.h>

void dollars(char *dest, char const *src)
{
    int i, j, srclen = 0, offset = 0, state = 0;
    int a = 0, b = 0;
    char *destbak = NULL;
    destbak = dest;

    srclen = strlen(src);
    *dest++ = '$';

    if(srclen >= 3)
    {
        a = (srclen - 2) / 3;
        b = (srclen - 2) % 3;

        for(i = 0; i < a; ++i)
        {
            if(i == 0)
            {
                for(j = 0; j < b; ++j)
                {
                    *(dest++) = *(src++);
                }
            }
            if(b != 0)
                *(dest++) = ',';
            for(j = 0; j < 3; ++j)
                *(dest++) = *(src++);
        }
        if((a == 0) && (b != 0))
        {
            for(j = 0; j < b; ++j)
            {
                *(dest++) + *(src++);
            }
        }
        *(dest++) = '.';

        for(; *src != '\0'; dest++, src++)
            *dest = *src;
        *dest = '\0';
    }
    else
    {
        memset(dest, '0', 4);
        *(++dest) = '.';
        dest++;
        for(i = 0; i < 2 - srclen; ++i)
            *(dest++) = '0';
        for(i = 0; i < srclen; ++i)
            *(dest + i) = *(src + i);
    }
}

int dollchk(char *src)
{
    int i;
    for(i = 0; *(src + i) != '\0'; ++i)
    {
        if(!isdigit(*(src + i)))
            return 0;
    }
    return 1;
}

int main()
{
    char temp[20] = {0};
    char dollar[20];
    char *dest = temp;
    int state = 0;

    printf("Please enter some number:");
    scanf("%s", &dollar);
    state = dollchk(dollar);

    if(!state)
    {
        printf("Data error!\n");
        return 0;
    }

    printf("%s\n", dest);
    printf("%s\n", dollar);

    dollars(dest, dollar);
    if(*dest != '\0')
        printf("%s\n", dest);
    return 0;
}
