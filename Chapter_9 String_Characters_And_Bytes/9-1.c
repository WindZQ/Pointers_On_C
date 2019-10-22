#include <stdio.h>
#include <ctype.h>

void print_count(char *string)
{
    float sum = 0, cntrl = 0, space = 0, digit = 0, lower = 0, upper = 0, punct = 0, unprint = 0;
    while(*string != '\0')
    {
        char ch = *string;
        if(iscntrl(ch))
            cntrl++;
        if(isspace(ch))
            space++;
        if(isdigit(ch))
            digit++;
        if(islower(ch))
            lower++;
        if(isupper(ch))
            upper++;
        if(ispunct(ch))
            punct++;
        if(!isprint(ch))
            unprint++;
        sum++;
        string++;
    }
    printf("all character is %.1f\n", sum);
    printf("control character possess is % %3.0f\n", (cntrl / sum) * 100);
    printf("space character  possess is %% %3.0f\n", (space / sum) * 100);
    printf("digit character  possess is %% %3.0f\n", (digit / sum) * 100);
    printf("lower character  possess is %% %3.0f\n", (lower / sum) * 100);
    printf("upper character  possess is %% %3.0f\n", (upper / sum) * 100);
    printf("punct character  possess is %% %3.0f\n", (punct / sum) * 100);
    printf("do not print character  possess is %% %3.0f\n",100 * (unprint/sum));
}

int main()
{
    float sum = 0;
    char string[1000];
    gets(string);
    print_count(string);
    return 0;
}
