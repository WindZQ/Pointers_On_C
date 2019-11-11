#include <stdlib.h>
#include <stdio.h>

#define MAX_OK_PAND  (int)((((long)RAND_MAX + 1) / 6) * 6 - 1)

int thorw_die(void)
{
    static int is_seeded = 0;
    int value = 0;
    if(!is_seeded)
    {
        is_seeded = 1;
        srand((unsigned int)time(NULL));
    }
    do
    {
        value = rand();
    }while(value > MAX_OK_PAND);
    return value % 6 + 1;
}

int main()
{
    int result = 0;
    result = thorw_die();
    printf("The result: %d\n", result);
    return 0;
}
