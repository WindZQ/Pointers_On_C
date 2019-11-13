#include <stdio.h>
#include <math.h>

double wind_chill(double temp, double velocity)
{
    int t = 33;
    double sum = 10.45 + 10 * sqrt(velocity) - velocity;
    double sum1 = 10.45 + 10 * sqrt(1.78816) - 1.78816;
    temp = sum / sum1;
    return temp;
}

int main(void)
{
    double temp = 0, velocity = 0, result = 0;
    printf("Please input tmep and velocity:");
    scanf("%lf%lf", &temp, &velocity);
    result = wind_chill(temp, velocity);
    printf("The result is %lf", result);
    return 0;
}
