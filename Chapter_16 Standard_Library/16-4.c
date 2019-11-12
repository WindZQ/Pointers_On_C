#include <stdio.h>

const char * getWeekdayByYearday(int iY, int iM, int iD)
{
    int iWeekDay = -1;
    if (1 == iM || 2 == iM)
    {
        iM += 12;
        iY--;
    }
    iWeekDay = (iD + 1 + 2 * iM + 3 * (iM + 1) / 5 + iY + iY / 4 - iY / 100 + iY / 400) % 7;
    switch(iWeekDay)
    {
        case 0 : return "Sunday"; break;
        case 1 : return "Monday"; break;
        case 2 : return "Tuesday"; break;
        case 3 : return "Wednesday"; break;
        case 4 : return "Thursday"; break;
        case 5 : return "Friday"; break;
        case 6 : return "Saturday"; break;
        default : return NULL; break;
    }
    return NULL;
}

int main(int argc, char **argv)
{
    int year,month,day;
    year = argv[1];
    month = argv[2];
    day = argv[3];
    const char * p = getWeekdayByYearday(year, month, day);
    printf("WeekDay : %s\n", p);
    printf("\n");
    return 0;
}
