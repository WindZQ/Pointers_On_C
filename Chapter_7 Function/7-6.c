#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX_LEN 128

static char *digits[] =
{
    "","ONE ","TWO ","THREE ","FOUR ","FIVE ",
    "SIX ","SEVEN ","EIGHT ","NINE ","TEN ",
    "ELEVEN ", "TWELVE ", "THIRTEEN ",
    "FOURTEEN ", "FIFTEEN ", "SIXTEEN ",
    "SEVENTEEN ", "EIGHTEEN ","NINETEEN"
};

static char *tens[] =
{
    "", "", "TWENTY ", "THIRTY ", "FORTY ",
    "FIFTY ", "SIXTY ", "SEVENTY ","EIGHTY ",
    "NINETY "
};

static char *magnitudes[] =
{
    "", "THOUSAND ", "MILLION ", "BILLION "
};

static void do_one_group(unsigned int amount, char *buffer, char **magnitude)
{
    int value = amount / 1000;
    if(value > 0)
        do_one_group(value, buffer, magnitude + 1);
    amount = amount % 1000;
    value = amount / 100;
    if(value > 0)
    {
        strcat(buffer, digits[value]);
        strcat(buffer, "HUNDRED");
    }
    value = amount % 100;
    if(value >= 20)
    {
        strcat(buffer, tens[value / 10]);
        value = value % 10;
    }
    if(value > 0)
        strcat(buffer, digits[value]);
    if(amount > 0)
        strcat(buffer, *magnitude);
}

void written_amount(unsigned int amount, char *buffer)
{
    if(amount == 0)
        strcpy(buffer, "ZERO");
    else
        do_one_group(amount, buffer, magnitudes);
    printf("The string of number is %s\n", buffer);
}

int main()
{
    unsigned int number;
    printf("Please input a number:");
    scanf("%d", &number);
    char *buffer = (char *)malloc(sizeof(char) * MAX_LEN);
    memset(buffer, 0, MAX_LEN);
    written_amount(number, buffer);
    return 0;
}
