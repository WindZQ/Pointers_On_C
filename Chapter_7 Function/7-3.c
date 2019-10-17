#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX_LEN 128
int ascii_to_integer(char *string)
{
    int string_len = 0, number = 0, i = 0;
    while(string[++i] != '\0')
        string_len++;
    for(i = 0; i < string_len; ++i)
    {
        if(!isdigit(string[i]))
            return 0;
        else
            number = number * 10 + string[i] - '0';
    }
    return number;
}

int main()
{
    char *string;
    int k;
    string = (char *)malloc(sizeof(char) * MAX_LEN);
    memset(string, 0, MAX_LEN);
    printf("Please input a string:");
    scanf("%s", string);
    printf("The input string is %s\n", string);
    printf("The string means number is ");
    k = ascii_to_integer(string);
    printf("%d\n", k);
    return 0;
}
