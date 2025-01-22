#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int year, month, day;
    int pday, pmonth;

    year = 1988;
    month = 2;
    day = 29;

    int yearday = day_of_year(year, month, day);
    printf("%d\n",yearday);

    month_day(year, yearday, &pmonth, &pday);

    printf("%d, %d\n", pmonth, pday);

    return 0;
}


int day_of_year(int year, int month, int day) {
    int i, leap;

    char (*ptr)[13] = daytab;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    // Decide which row of the array we are poiinting at
    if (leap) {
        leap = 1;
    }

    for (i = 1; i < month; i++) {
         day += *(ptr[leap] + i); 
    }
    return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    char (*ptr)[13] = daytab;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (leap) 
        leap = 1;

    for (i = 1; yearday > *(ptr[leap] + i); i++) {
        yearday -= *(ptr[leap] + i);
    }
    
    *pmonth = i;
    *pday = yearday;
    
}
