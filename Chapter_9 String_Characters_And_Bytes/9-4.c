#include <stdio.h>
#include <assert.h>
char *my_strcat(char *dst, const char *src)
{
    assert((dst !=NULL) && (src != NULL));
    char *ch = dst;
    while(*dst)
        dst++;
    while(*dst++ = *src++)
        ;
    return ch;
}

int main()
{

    char dst[32] = {0};
    char src[32] = {0};
    printf("Please input string:");
    scanf("%s%s", &dst, &src);
    char *ch = my_strcat(dst, src);
    printf("%s", ch);
    return 0;
}
