#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>

#define N 64

void dump(FILE *stream)
{
    long offset;
    unsigned char data[16];
    int len;
    char buffer[N];

    memset(buffer, ' ', N - 1);
    buffer[45] = '*';
    buffer[62] = '*';
    buffer[N - 1] = '\0';

    offset = 0;
    while((len = fread(data, 1, 16, stream)) > 0)
    {
        char *hex_ptr;
        char *char_ptr;
        int i;

        sprintf(buffer, "%06X", offset);
        hex_ptr = buffer + 8;
        char_ptr = buffer + 46;
        memset(hex_ptr, ' ', 35);
        memset(char_ptr, ' ', 16);

        for(i = 0; i < len; ++i)
        {
            sprintf(hex_ptr, "%02X", data[i]);
            hex_ptr += 2;
            *hex_ptr = ' ';

            if(i % 4 == 3)
                hex_ptr++;
            if(isprint(data[i]) || data[i] == ' ')
                *char_ptr++ = data[i];
            else
                *char_ptr++ = '.';
        }
        puts(buffer);
        offset += len;
    }
}

int main(int argc, char **argv)
{
    if(argc <= 1)
        dump(stdin);
    else
    {
        FILE *file;
        file = fopen(argv[1], "rb");
        if(file == NULL)
        {
            perror(argv[1]);
            exit(0);
        }
        dump(file);
        fclose(file);
    }
    return 0;
}
