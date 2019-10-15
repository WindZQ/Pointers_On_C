#include <stdio.h>
#include <string.h>

void reverse_string(char *string)
{
    char *head = string;
    char *tail = string + strlen(string) - 1;
    char temp;

    while(head < tail)
    {
        temp = *head;
        *head = *tail;
        *tail = temp;
        head++;
        tail--;
    }
}

int main()
{
    char source[] = "ABCDEF";
    printf("source: %s\n", source);
    reverse_string(source);
    printf("reverse: %s\n", source);
    return 0;
}
