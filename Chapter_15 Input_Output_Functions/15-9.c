#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 512

void search(char *filename, FILE *stream, char *string)
{
    char buffer[N];
    while(fgets(buffer, N, stream) != NULL)
    {
        if(strstr(buffer, string) != NULL)
        {
            if(filename != NULL)
                printf("%s: ", filename);
            fputs(buffer, stdout);
        }
    }
}

int main(int argc, char **argv)
{
    char *string;
    if(argc <= 1)
    {
        printf(stderr, "Usage: fgrep string file...\n");
        return -1;
    }

    string = *++argv;
    if(argc <= 2)
        search(NULL, stdin, string);
    else
    {
        while(*++argv != NULL)
        {
            FILE *stream;
            stream = fopen(*argv, "r");
            if(stream == NULL)
                perror(*argv);
            else
            {
                search(*argv, stream, string);
                fclose(stream);
            }
        }
    }
    return 0;
}
