#include <stdio.h>
#include <string.h>

int count_chars(char const *str, char const *chars)
{
    int count = 0, len = 0;
    char *pos = NULL;
    pos = str;

    while (( pos = strpbrk(pos, chars) ) != NULL )
    {
        count++;
        pos++;
    }

    return count;
}

int main (void)
{
    char str[] = "Hello world!";
    char chars[] = "ero";

    printf("%d\n", count_chars(str, chars));
    return 0;
}
