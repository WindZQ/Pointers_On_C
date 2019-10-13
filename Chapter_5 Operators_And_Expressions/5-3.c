#include <stdio.h>

unsigned int reverse_bits(unsigned int value)
{
    unsigned int i, answer = 0;
    for(i = 1; i != 0; i <<= 1)
    {
        answer <<= 1;
        if(value & 1)
            answer |= 1;
        value >>= 1;
    }
    return answer;
}

int main()
{
    unsigned int src, dst;
    printf("Please input the number:");
    scanf("%u", &src);
    dst = reverse_bits(src);
    printf("%u\n",dst);
    return 0;
}
