#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int unprint(int ch)
{
    return !isprint(ch);
}

int (*test[])(int ch) =
{
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    unprint,
};

#define COUNT (sizeof(test) / sizeof(test[0]))

char *label[] =
{
    "control",
    "whitespace",
    "digit",
    "lower case",
    "upper case",
    "punctuation",
    "unprintable"
};

int value[COUNT];
int total;

int main()
{
    int i, ch;
    while((ch = getchar()) != EOF)
    {
        total += 1;
        for(i = 0; i < COUNT; ++i)
        {
            if(test[i](ch))
                value[i]++;
        }
    }
    if(total == 0)
        printf("no character in the input\n");
    else
    {
        for(i = 0; i < COUNT; ++i)
        {
            printf("%3.0f%% %s characters\n", value[i] * 100.0 / total, label[i]);
        }
    }
    return 0;
}
