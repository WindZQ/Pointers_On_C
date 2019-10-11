#include <stdio.h>

void copy_n(char dst[], char src[], int n)
{
    int dst_index = 0, src_index = 0;
    for(; dst_index < n; ++dst_index)
    {
        dst[dst_index] = src[src_index];
        if(src[src_index] != 0)
            src_index++;
    }
}

int main()
{
    char dst[64] = {0};
    char src[] = "abcdefg";
    copy_n(dst, src, 7);
    for(int i = 0; i < 7; ++i)
        printf("%c", dst[i]);
    return 0;
}
