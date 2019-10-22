#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void *my_memcpy(void *dst, const void *src, unsigned int count)
{
    assert(dst);
    assert(src);
    void *ret = dst;
    if(dst <= src || (char *)dst >= ((char *)src + count)
)
    {
        while(count--)
        {
            *(char *)dst = *(char *)src;
            dst = (char *)dst + 1;
            src = (char *)src + 1;
        }
    }
    else
    {
        dst = (char *)dst + count - 1;
        src = (char *)src + count - 1;
        while(count--)
        {
            *(char *)dst = *(char *)src;
            dst = (char *)dst - 1;
            src = (char *)src - 1;
        }
    }
    return ret;
}

char *my_strcpy(char *dst, const char *src)
{
    assert(dst != NULL);
    assert(src != NULL);
    char *ret = dst;
    my_memcpy(dst, src, strlen(src) + 1);
    return ret;
}

int main()
{
    char src[32] = {0};
    char dst[32] = {0};
    printf("Please input the character:");
    scanf("%s", &src);
    my_strcpy(dst, src);
    printf("The result:%s", dst);
    return 0;
}
