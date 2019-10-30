#include <stdio.h>
#include <stdlib.h>

int *getInputToArray()
{
    int *array;
    int count = 0;
    int num;

    array = malloc(1);
    array[0] = count;
    while(scanf("%d", &num) != EOF)
    {
        count++;
        array = realloc(array, (count + 1) * sizeof(int));
        array[count] = num;
        array[0] = count;
    }
    return array;
}

int main()
{
    int *arr = getInputToArray();
    printf("%d\n", arr[0]);
    return 0;
}
