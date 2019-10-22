#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t my_strnlen(char const *string, int size)
{
    register size_t length;
    for(length = 0; length < size; ++length)
        if(*string++ == '\0')
            break;
    return length;
}

int main()
{
    char string[] = "asdfal";
    printf("The result: %d", my_strnlen(string, 3));
    return 0;
}
