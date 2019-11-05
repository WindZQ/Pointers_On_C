#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 20

int main()
{
    char ch;
    char sourcefile[N], targetfile[N];
    FILE *source, *target;

    printf("Please enter the name of a text file to act as the source file:");
    scanf("%s", sourcefile);
    printf("Please enter the name of a text file to act as the output file:");
    scanf("%s", targetfile);

    if((source = fopen(sourcefile, "r")) == NULL)
    {
        printf("Could not open file %s for input.\n", sourcefile);
        exit(EXIT_FAILURE);
    }

    if((target = fopen(targetfile, "w")) == NULL)
    {
        printf("Could not open file %s for output.\n", targetfile);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(source)) != EOF)
    {
        if(islower(ch))
            ch = toupper(ch);
        putc(ch, target);
    }

    if(fclose(source) != 0)
        printf("Could not close file %s.\n", sourcefile);
    if(fclose(target) != 0)
        printf("Could not closet file %s.\n", targetfile);
    return 0;
}
