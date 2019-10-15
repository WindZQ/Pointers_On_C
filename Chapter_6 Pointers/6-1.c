#include <stdio.h>

char *find_char(char const *source, char const *chars)
{
    char const *sptr = source;
    char const *cptr = chars;

    if(NULL == sptr || NULL == chars)
        return NULL;
    while(*sptr != '\0')
    {
        cptr = chars;
        while(*cptr != '\0')
        {
            if(*cptr == *sptr)
            {
                printf("chars: 0x%p\n", chars);
                return (char *)cptr;
            }
            cptr++;
        }
        sptr++;
    }
    return NULL;
}

int main()
{
    char *source = "ABCDEF";
    char *str1 = "XYZ";
    char *str2 = "XRCQEF";
    char *chars = str1;
    char *ptr = NULL;

    ptr = find_char(source, chars);
    printf("0x%p\n", ptr);
    chars = str2;
    ptr = find_char(source, chars);
    printf("0x%p\n", ptr);
    return 0;
}
