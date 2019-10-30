#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getInputToString()
{
    char *str = malloc(1);
    char *tmp;
    int length = 1;
    char ch;

    while((ch = getchar()) != EOF)
    {
        length++;
        tmp = realloc(str, length * sizeof(char));
        if(tmp != NULL)
        {
            strcpy(tmp, str);
            tmp[length - 2] = ch;
            tmp[length - 1] = '\0';
        }
        else
            return NULL;
        str = tmp;
    }
    return str;
}

int main()
{
    char *str = getInputToString();
    printf("%s", str);
    return 0;
}
