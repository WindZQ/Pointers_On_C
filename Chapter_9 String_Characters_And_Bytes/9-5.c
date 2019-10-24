#include <stdio.h>
#include <string.h>

#define  M  12
#define  N  16

void my_strncat(char *dest, char *src, int dest_len)
{
    size_t len = 0, dstlen = 0, srclen = 0, restlen = 0;
    dstlen = strlen(dest);
    srclen = strlen(src);

    len = ( (restlen = dest_len - dstlen - 1) > srclen ? srclen : restlen );
    strncat(dest, src, len);
}

void show_string(char *str)
{
    while (*str != '\0')
        printf("%c", *str++);
    putchar('\n');
}

int main (void)
{
    char dst[M] = "Hello!";
    char src[N] = "I'm here!";
    char *dstp = dst;
    char *srcp = src;

    my_strncat(dst, src, M);

    show_string(dstp);
    show_string(srcp);

    getchar();
    return 0;
}
