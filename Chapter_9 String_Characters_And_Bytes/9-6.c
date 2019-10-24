#include <stdio.h>
#include <string.h>

char *my_strcpy_end(char *dst, char *src)
{
    int i, dstlen = 0, srclen = 0;

    dstlen = strlen(dst);
    srclen = strlen(src);

    if ( dstlen >= srclen )
        strcpy(dst, src);
    else
        strncpy(dst, src, dstlen);

    for ( i = 0; *(dst + i) != '\0'; i++);
    return dst + i;
}

int main (void)
{
    char *p = NULL;
    char dst[] = "Hello world";
    char src[] = "123456789123456789";

    p = my_strcpy_end(dst, src);

    printf("%c\n", *(p - 1));

    getchar();
    return 0;
}
