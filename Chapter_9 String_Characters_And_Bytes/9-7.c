#include <stdio.h>
#include <string.h>

char *my_strrchr(char *str, int ch)
{
    if(NULL == str)
        return NULL;
    char *result = NULL;
    while((str = strchr(str, ch)) != NULL)
    {
        printf("*str is %c\n", *str);
        result = str;
        ++str;
    }
    return result;
}

int main()
{
    char *str = "hello, world!";
    char ch = 'y';
    printf("my_strrchr(%s, %d) is %s\n", str, ch, my_strrchr(str, ch));
    return 0;
}
