#include <stdio.h>

int main()
{
    int ch;
    char checksum = -1;
    while((ch = getchar()) != EOF)
    {
        putchar(ch);
        checksum += ch;
    }
    printf("%d\n", checksum);
    return 0;
}
