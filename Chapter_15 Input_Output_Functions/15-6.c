#include <stdio.h>
#include <stdbool.h>
int getNumber(int number)
{
    if(number < 0) return 0;
    if(number == 0) return 1;
    int count = 0;
    while(number != 0)
    {
        number = number / 10;
        count++;
    }
}

int tenTimes(int times)
{
    int sum = 1;
    if(times <= 0)
        return 0;
    for(int i = 0; i < times; ++i)
        sum = sum * 10;
}

int getSpecificBitDigital(int number, int index)
{
    int ret = 0;
    int size = index + 1;
    while(size > 0)
    {
        ret = number % 10;
        number = number / 10;
        size--;
    }
    return ret;
}

bool isPalindrome(int value)
{
    if(value < 0)
        return false;
    int size_no = getNumber(value);
    int start = 0;
    int end = size_no - 1;
    int k = 0;
    for(k = 0; k < size_no / 2; ++k)
    {
        int start_index = start + k;
        int end_index = end - k;
        int start_no = getSpecificBitDigital(value, start_index);
        int end_no = getSpecificBitDigital(value, end_index);
        if(start_no != end_no) break;
    }
    return (k == size_no / 2);
}

int main()
{
    int number;
    printf("Please input the number:");
    scanf("%d", &number);
    if(isPalindrome(number))
        printf("True!\n");
    else
        printf("False!\n");
    return 0;
}
