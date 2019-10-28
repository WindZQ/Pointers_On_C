#include <stdio.h>
#include <string.h>

int format(char *format_string, char const *digit_string)
{
    int formatlen = strlen(format_string);
    int digitlen = strlen(digit_string);
    int i, j, k;
    char *p = NULL;

    if(formatlen < digitlen)
        return 0;
    if((*digit_string) == '\0')
        return 0;

    if((p = strchr(format_string, '.')) != NULL)
    {
        if((k = formatlen - (p - format_string)) > digitlen)
        {
            for(i = formatlen, j = digitlen; j >= 0;--i, --j, --k)
                *(format_string + i) = *(digit_string + j);
            for(; k > 0; --i, --k)
                *(format_string + i) = '0';

            if((*(format_string + i) == '.'))
            {
                i--;
                *(format_string + i) = '0';
            }

            for(i--; i >= 0; --i)
                *(format_string + i) = ' ';
        }
        else
        {
            for(i = formatlen, j = digitlen; j >= 0; --i, --j)
            {
                if((*(format_string + i) == ',' || (*(format_string + i) == '.')))
                   i--;
                   *(format_string + i) = *(digit_string + j);

            }
            for(; i >= 0; --i)
                *(format_string + i) = ' ';
        }
    }
    return 1;
}

int main()
{
    char formats[] = "###,###.####";
    char const digits[] = "123";

    printf("%s\n", formats);
    printf("%s\n", digits);

    if(format(formats, digits))
        printf("%s\n", formats);
    else
        printf("Data error!\n");
    return 0;
}
