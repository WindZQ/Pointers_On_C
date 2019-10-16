#include <stdio.h>
#define MAX_LEN 1000000
#define MAX_ARR_SIZE (MAX_LEN / 8)
#define CHAR_BIT (sizeof(char) * 8)


unsigned int char_offset(unsigned bit_number)
{
    return bit_number / CHAR_BIT;
}

unsigned int bit_offset(unsigned bit_number)
{
    return bit_number % CHAR_BIT;
}

void set_bit(char bit_array[], unsigned bit_number)
{
    bit_array[char_offset(bit_number)] |= 1 << bit_offset(bit_number);
}

void clear_bit(char bit_array[], unsigned bit_number)
{
    bit_array[char_offset(bit_number)] &= ~(1 << bit_offset(bit_number));
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
    if(value != 0)
        set_bit(bit_array, bit_number);
    else
        clear_bit(bit_array, bit_number);
}

int test_bit(char bit_array[], unsigned bit_number)
{
    return (bit_array[char_offset(bit_number)] & (1 << bit_offset(bit_number))) != 0;
}

void find_primer_bit(char bit_array[], unsigned long int length)
{
    clear_bit(bit_array, 0);
    clear_bit(bit_array, 1);
    unsigned int tmp, loc, index = 2;
    while(index < length)
    {
        tmp = index;
        while((tmp += index) < length)
            clear_bit(bit_array, tmp);
        index++;
    }
}

int main()
{
    char bit_array[MAX_ARR_SIZE];
    unsigned int count = 0, index = 0, total = 0, limit = 100000;
    while(index < MAX_ARR_SIZE)
        bit_array[index++] = 0xff;

    find_primer_bit(bit_array, MAX_LEN);
    index = 0;
    while(index < MAX_LEN)
    {
        if(index == limit)
        {
            printf("%-6d %-6d avg: %5.2f\n", index - 100000, index, (float)count / 100);
            count = 0;
            limit += 100000;
        }
        if(test_bit(bit_array, index))
        {
            count++;
            total++;
        }
        index++;
    }
    printf("\n Total:%d primer\n", total);
    return 0;
}
