#include <stdio.h>
#define method1  1
#define method2  0
#if method1
int store_bit_field(int orginal_value, int value_to_store, unsigned starting_bit, unsigned ending_bit)
{
    unsigned int mask, num, unmask;
    unsigned int i = 31 - starting_bit;

    mask = (~0 << ending_bit) & (~0 >> i);
    unmask = ~mask;
    unmask &= orginal_value;
    mask = mask & (value_to_store << ending_bit);
    num = mask | unmask;
    return num;
}
#endif

#if method2
int starting_bit(int orginal_value, int value_to_store, unsigned starting_bit, unsigned ending_bit)
{
    int value, i = ending_bit;
    int unmask = 0, mask = 0;
    int num = starting_bit - ending_bit + 1;
    while(num != 0)
    {
        mask <<= 1;
        mask |= 1;
        num--;
    }
    while(i != 0)
    {
        i--;
        mask <<= 1;
    }
    unmask = ~mask;
    orginal_value &= unmask;
    i = ending_bit;
    while(i != 0)
    {
        i--;
        value_to_store <<= 1;
    }
    value = value_to_store & mask;
    value |= orginal_value;
    return value;
}
#endif

int main()
{
    unsigned num, starting_bit, ending_bit;
    int orginal_value, value_to_store;
    printf("Please input number:");
    scanf("%x%x%d%d", &orginal_value, &value_to_store, &starting_bit, &ending_bit);
    num = store_bit_field(orginal_value, value_to_store, starting_bit, ending_bit);
    printf("0x%x", num);
    return 0;
}
