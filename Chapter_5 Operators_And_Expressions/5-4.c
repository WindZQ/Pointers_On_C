#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

void set_bit(char bit_array[], unsigned bit_number)
{
    printf("操作之前：%s\n", bit_array);
    bit_array[bit_number - 1] = '1';
    printf("操作之后：%s\n", bit_array);
}

void clear_bit(char bit_array[], unsigned bit_number)
{
    printf("操作之前：%s\n", bit_array);
    bit_array[bit_number-1] = '0';
    printf("操作之后：%s\n", bit_array);
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
    printf("操作之前：%s\n", bit_array);
    if (value == 0)
        bit_array[bit_number - 1] = '0';
    else
        bit_array[bit_number - 1] = '1';
    printf("操作之后：%s\n", bit_array);
}

int test_bit(char bit_array[], unsigned bit_number)
{
    int bour;
    if (bit_array[bit_number - 1] != 0 )
        bour = 1 ;
    else
        bour = 0 ;
    return bour ;
}

int main()
{
    char ch;
    int value, num, len;
    unsigned bit_number;
    char bit_array[MAX];

    printf("请输入num和value的值(value为1或0)：");
    scanf ( "%d %d", &num, &value );
a:
    if(value != 0 && value != 1 )
    {
        printf("请重新输入value的值(value为1或0)：");
        scanf("%d", &value);
        goto a;
    }
    itoa(num, bit_array, 2);
    len = strlen(bit_array);
    printf("请输入bit_number(bit_number小于%d)：", len + 1 );
    scanf("%d", &bit_number);
b:
    if (bit_number < 0 || bit_number > len)
    {
        printf("请重新输入bit_number(bit_number小于%d)：", len + 1);
        scanf("%d", &bit_number);
        goto b ;
    }

    set_bit(bit_array, bit_number);
    clear_bit(bit_array, bit_number);
    assign_bit(bit_array, bit_number, value);
    printf("操作之后：%d\n", test_bit(bit_array, bit_number));
    return 0;
}
