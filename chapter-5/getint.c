#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn) {
    int c, sign;

    // walk over any blank space
    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;                            // its not a number
    }
 
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        c = getch();                        // Skip over the symbol
        if (!isdigit(c)) {                  // Run it back if its not a digit after the symbol
            ungetch(c);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');        
 
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
