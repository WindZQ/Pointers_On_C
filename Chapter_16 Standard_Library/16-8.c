#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 512

int main(void)
{
    int age = 0, totalAge = 0, peopleNum = 0;
    float avgAge = 0.0;
    FILE *file = NULL;
    char info[MAX_LEN] = {0};
    char *infoPtr = NULL;
    file = fopen("1.txt", "r");

    while(fgets(info, MAX_LEN, file))
    {
        infoPtr = info;
        peopleNum = 0;
        totalAge = 0;
        while((age = strtol(infoPtr, &infoPtr, 10)))
        {
            totalAge += age;
            peopleNum++;
        }
        avgAge = (float)totalAge / peopleNum;
        printf("%s avg: %5.2f\n", info, avgAge);
    }
    return 0;
}
