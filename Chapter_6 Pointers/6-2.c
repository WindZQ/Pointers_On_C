#include <stdio.h>

int del_substr(char *str, char const *substr)
{
    if(NULL == str || NULL == substr)
        return 0;
    char *source = str, *sub = substr, *temp = NULL;
    while(*source != '\0')
    {
        sub = substr;
        temp = source;
        while(*temp++ == *sub++)
        {
            if(*sub == '\0')
            {
                while(*(temp + 1) != '\0')
                    *source = *temp;
                return 1;
            }
        }
        source++;
    }
    return 0;
}

int main()
{
    char *source = "ABCDEF";
    char *str1 = "CGE";
    char *str2 = "CDE";
    int isDel;
    isDel = del_substr(source, str1);
    printf("del_substr: %d\n", isDel);
    isDel = del_substr(source, str2);
    printf("del_substr: %d\n", isDel);
    return 0;
}
