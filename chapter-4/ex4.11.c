#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getch(void);
void ungetch(int);

int getop(char *s) {
    int i, c;
    static int next = 0;

    if (next != 0) {
        c = next;
        next = 0;
    }
    else 
        c = getchar();

    while (c == ' ' || c == '\t') 
        c = getchar();
        
    *s = c;
    *++s = '\0';

    // Return c if its not a number 
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    // check for negative numbers
    if (c == '-') {
        next = getch();
        if (!isdigit(next) && next != '.') {
            return c;
        }
        else {
            *--s = '-';
            *++s = next; 
            c = next;
        }
    }

    // collect all the digits of the number, including any after a decimal
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;

    // Set the end of the str with the null boi
    *s = '\0';

    // Check for end of file, if not, push back into the input the last getch()
    if (c != EOF)
        next = c;
    // Return a number if we make it all the way down here
    printf("%s\n", s);
    return NUMBER;
}
