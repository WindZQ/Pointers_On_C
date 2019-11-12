#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t current_time;
    struct tm *time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    switch(time_info->tm_hour)
    {
    case 1:
        printf("hour hand on 1\n");
        break;
    case 2:
        printf("hour hand on 2\n");
        break;
    case 3:
        printf("hour hand on 3\n");
        break;
    case 4:
        printf("hour hand on 4\n");
        break;
    case 5:
        printf("hour hand on 5\n");
        break;
    case 6:
        printf("hour hand on 6\n");
        break;
    case 7:
        printf("hour hand on 7\n");
        break;
    case 8:
        printf("hour hand on 8\n");
        break;
    case 9:
        printf("hour hand on 9\n");
        break;
    case 10:
        printf("hour hand on 10\n");
        break;
    case 11:
        printf("hour hand on 11\n");
        break;
    case 12:
        printf("hour hand on 12\n");
        break;
    default:
        break;
    }

    switch(time_info->tm_min)
    {
    case 5:
        printf("min hand on 1\n");
        break;
    case 10:
        printf("min hand on 2\n");
        break;
    case 15:
        printf("hour hand on 3\n");
        break;
    case 20:
        printf("hour hand on 4\n");
        break;
    case 25:
        printf("hour hand on 5\n");
        break;
    case 30:
        printf("hour hand on 6\n");
        break;
    case 35:
        printf("hour hand on 7\n");
        break;
    case 40:
        printf("hour hand on 8\n");
        break;
    case 45:
        printf("hour hand on 9\n");
        break;
    case 50:
        printf("min hand on 10\n");
        break;
    case 55:
        printf("min hand on 11\n");
        break;
    case 60:
        printf("min hand on 12\n");
        break;
    default:
        break;
    }
    return 0;
}
