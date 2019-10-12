#include <stdio.h>
#include <string.h>

int main()
{
    char string[10] = "";
    char string1[10] = "";
    int r;
    while(string[0] != 'Z')
    {
        gets(string);
        r = strcmp(string, string1);
        if(!r)
        {
            printf("\n");
            puts(string);
        }
        strcpy(string1, string);
    }
    return 0;
}
