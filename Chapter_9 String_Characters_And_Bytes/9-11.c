#include <stdio.h>
#include <string.h>

int main()
{
    char input[101];
    char chars[] = "the";
    int i = 0, count = 0;
    char *pos = NULL;

    printf("Please enter some words: \n");
    scanf("%s", input);
    printf("%s\n", input);

    pos = input;
    while((pos = strstr(pos, chars)) != NULL)
    {
        pos++;
        count++;
    }
    printf("There are %d \"%s\"!", count, chars);
    return 0;
}
