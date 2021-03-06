#include <stdio.h>
#include <stdarg.h>

int array_offset(int array_info[], ...)
{
    int dimension = array_info[0];
    if(1 > dimension || 10 < dimension)
        return -1;
    int now, offset, index, muti;
    va_list arg;
    va_start(arg, array_info);

    for(now = 1, offset = 0, muti = 1; now <= dimension * 2; now += 2)
    {
        index = va_arg(arg, int);
        if(index < array_info[now] || index > array_info[now + 1])
            return -1;
        if(now == 1)
            muti = 1;
        else
            muti *= array_info[now - 1] - array_info[now - 2] + 1;
     }
    va_end(arg);
    return offset;
}

int main()
{
    int array_info[] = {3, 4, 6, 1, 5, -3, 3};
    printf("%d\n", array_offset(array_info, 4, 1, -3));
    printf("%d\n", array_offset(array_info, 4, 2, -3));
    printf("%d\n", array_offset(array_info, 4, 1, -1));

    return 0;
}
