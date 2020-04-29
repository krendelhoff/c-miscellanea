#include "libft.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    char *tmp;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        tmp = *daytab + 13;
    else
        tmp = *daytab;
    while (0 < --month)
        day += *tmp++;
    return (day);
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    char *tmp;
    int i;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        tmp = *daytab + 13;
    else
        tmp = *daytab;
    i = 1;
    while (yearday > *tmp)
    {
        yearday -= *tmp++;
        i++;
    }
    *pmonth = i;
    *pday = yearday;
}
