#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void print(char *format, ...)
{
    va_list arg;
    char ch, *str;
    va_start(arg, format);
    while((ch = *format++) != '\0')
    {
        if(ch != '%')
        {
            putchar(ch);
            continue;
        }
        switch(*format != '\0' ? *format++ : '\0')
        {
        case 'd':
            printf_integer(va_arg(arg, int));
            break;
        case 'f':
            printf_float(va_arg(arg, float));
            break;
        case 'c':
            putchar(va_arg(arg, int));
            break;
        case 's':
            str = va_arg(arg, char *);
            while(*str != '\0')
                putchar(*str++);
            break;
        }
    }
}

int main()
{
    int number;
    printf("Please input a number:");
    scanf("%d", &number);
    print(number);
    return 0;
}
