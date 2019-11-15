#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_compare(void const *num, void const *num1)
{
    return (*(int *)num - *(int *)(num1));
}

void print_array(int *array, int len)
{
    for(int i = 0; i < len; ++i)
        printf("%d ", array[i]);
}

void insert_sort(void *array, size_t n_elements, size_t n_size, int (*handle)(void const *num, void const *num1))
{
    char *temp = malloc(n_size);
    unsigned int index = 1;
    unsigned int i = 0, j = 0, mov = 0;
    for(i = 1; i < n_elements; ++i)
    {
        for(j = 0; j < index; ++j)
        {
            if(handle(array + j * n_size, array + i * n_size) > 0)
            {
                memcpy(temp, array + i * n_size, n_size);
                for(mov = index; mov > j; --mov)
                    memmove(array + mov * n_size, array +(mov - 1) * n_size, n_size);
                memcpy(array + j * n_size, temp, n_size);
            }
        }
        index++;
    }
}

int main(void)
{
    int array[10] = {4, 1, 17, 2, 8, 9, 22, 12, 7, 5};
    insert_sort(array, 10, sizeof(int), int_compare);
    print_array(array, 10);
    return 0;
}
