#include <stdio.h>

int main()
{
    int ch;

    while((ch = getchar()) != EOF)
    {
        if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
        {
            if(ch >= 'N' && ch <= 'Z' || ch >= 'n' && ch <= 'z')
                ch -= 13;
            else
                ch += 13;
        }
        putchar(ch);
    }
    return 0;
}
