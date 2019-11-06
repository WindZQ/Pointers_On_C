#include <stdio.h>
#include <stdlib.h>
#define N 512

int main()
{
    char buffer[N];
    while(fgets(buffer, N, stdin) != NULL)
    {
        int age[N];
        int members, sum = 0, i;
        members = sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d", age[0], age[1], age[2], age[3], age[4], age[5], age[6], age[7], age[8], age[9]);
        continue;
        for(i = 0;i < members; ++i)
            sum += age[i];
        printf("%5.2f: %s", (double)sum / members, buffer);
    }
    return 0;
}
