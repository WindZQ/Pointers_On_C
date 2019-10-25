#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palindrome(char *string)
{
    int i, j = 0;
    int len = strlen(string);
    char *strcopy = NULL;
    strcopy = malloc((len + 1) * sizeof(char));
    for(i = 0; i < len; i++)
    {
        if(isalpha(*(string + i)))
        {
            *(strcopy + j) =  tolower(*(string + i));
            j++;
        }
    }
    *(strcopy + j) = '\0';

    len = strlen(strcopy);
    for(i = 0; i < (len / 2); i++)
    {
        if ((*(strcopy + i)) != (*(strcopy + (len - i - 1))))
            return 0;
    }

    return 1;
}

int main (void)
{
    char string[] = "Madam, I'm Adam!";
    int result = 0;

    result = palindrome(string);
    printf("%d\n", result);

    return 0;
}
