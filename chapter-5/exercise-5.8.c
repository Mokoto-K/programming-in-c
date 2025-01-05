/*There is no error checking in day_of_year or month_day. Remedy this defect.*/

/*My notes after adding minor error catching: The only problem i really see is a
seg fault error for month_day if a yearday isnt inside the range of the daytab 
ie less then the number of days in a year. Otherwise all other errors or more 
like "true bugs" as in you will just get a returned number that doesnt make sense
like day 55555 in a year. There are a few ways these can happen and arnt really
errors but bugs and for this exercise i would argue its pointless as if you want
to know the day number in year 339393 for month 69 and day 420... you deserve
a dumb answer. Obviously you wouldnt let this happen in production as these 
return values or setting the pointers to these values would probably cause larger
problems somewhere else in your program as you are probably using them elsewhere.

eh maybe ill change my tune and do all this protection tomorrow... i dunno
*/
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

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++) {
         day += daytab[leap][i];
    }
    return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if ((leap == 0 && yearday > 365 || yearday < 1) || (leap == 1 && yearday > 366 || yearday < 1)) {
        printf("There isn't %d days in year %d\n", yearday, year);
        *pmonth = 0;
        *pday = 0;
    }
    else {
        for (i = 1; yearday > daytab[leap][i]; i++) {
            yearday -= daytab[leap][i];
        }
        *pmonth = i;
        *pday = yearday;
    }
}
