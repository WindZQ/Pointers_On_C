#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substr(char dst[], char src[], int start, int len)
{
    char *temp = dst;
    int dst_len = 0, src_len = strlen(src);
    if(start < 0 || len <= 0 || src_len < start)
        printf("Error!\n");
    for(int i = 0; i < start; ++i)
        src++;
    while(dst_len < len && (*temp++ = *src++) != '\0')
        dst_len++;
    *temp = '\0';
    return dst_len;
}

int main()
{
    char string[] = "hello-my-college";
    char dst[100] = {0};
    int ret = 0, num = 0, count = 0;
    printf("Please input the len the num is:");
    scanf("%d%d", &num, &count);
    ret = substr(dst, string, num, count);
    printf("dst array length: %d\n", count);
    printf("dst array: %s\n", dst);
    return 0;
}
