#include <stdio.h>
#include <math.h>
double payment(double amount, double interset, int years)
{
    double sum = amount * (interset / 100);
    years = -years;
    double sum1 = 1 - pow(1 + interset / 100, (double)years);
    double temp = 0.0;
    temp = sum / sum1;
    return temp;
}

int main(void)
{
    double amount = 0.0, interset = 0.0, result = 0.0;
    int years = 0;
    printf("Please intput amount interset and years:");
    scanf("%lf%lf%lf", &amount, &interset, &years);
    result = payment(amount, interset, years);
    printf("The result is %.6f", result);
    return 0;
}
