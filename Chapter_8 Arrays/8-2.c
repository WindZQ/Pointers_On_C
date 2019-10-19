#include <stdio.h>
#include <stdlib.h>
#include <float.h>

static double income_limits[] =
{
    0,23350,56550,117950,256500,DBL_MAX
};

static double tax[] =
{
    0,3502.50,12789.50,31832.50,81710.50
};

static double p[] =
{
    0.15,0.28,0.31,0.36,0.396
};

double single_tax(double income)
{
    int category;
    for(category = 1; income >= income_limits[category]; ++category)
        ;
    category -= 1;
    return tax[category] + p[category] * (income - income_limits[category]);
}

int main()
{
    double income;
    printf("Please input a number:");
    scanf("%lf", &income);
    printf("The tax should be %lf\n", single_tax(income));
    return 0;
}
