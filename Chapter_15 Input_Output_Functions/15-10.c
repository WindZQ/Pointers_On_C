#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum(FILE *input, FILE *output)
{
    unsigned int check = 0;
    int value;
    while((value = fgetc(input)) != EOF)
        check += value;
    fprintf(output, "%d", check);
}

int main(int argc, char **argv)
{
    if(argc <= 1)
        sum(stdin, stdout);
    else if(strcmp(argv[1], "-f") == 0)
    {
        if(argc == 2)
        {
            printf("Illegal, it is not input filename!\n");
            return 1;
        }
        else
        {
            int i;
            FILE *input, *output;
            for(i = 2; i < argc; ++i)
            {
                char filename[256];
                strcpy(filename, argv[i]);
                strncat(filename, ".cks", 4);
                output = fopen(filename, "w");
                input = fopen(argv[i], "r");
                if(NULL == output)
                {
                    perror("input");
                    return -1;
                }
                sum(input, output);
                fclose(input);
                fclose(output);
            }
        }
    }
    else
    {
        int i;
        FILE *input;
        for(i = 1; i < argc; ++i)
        {
            input = fopen(argv[i], "r");
            if(NULL == input)
            {
                perror("input");
                return -1;
            }
            sum(input, stdout);
            fclose(input);
        }
    }
    return 0;
}
