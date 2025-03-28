#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int pmonth, pday;
    
    month_day(1988, day_of_year(1988,2,29), &pmonth, &pday); 
    printf("%d, %d\n", pmonth, pday);

    return 0;

}

int day_of_year(int year, int month, int day) {
    int i, leap;
    
    if (month > 12 || day > 31) {
        printf("Date does not exist in the caledar year\n");
        return 1;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++, (*daytab[leap])++)
        day += *daytab[leap];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > *daytab[leap]; i++, (*daytab[leap])++)
        yearday -= *daytab[leap];
    *pmonth = i;
    *pday = yearday;
}
