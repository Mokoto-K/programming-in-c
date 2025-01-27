#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);


int main(int argc, char *argv[]) {
    int ip[100];
    char *ap = "1 2 3 4 5 6 7 8 9";


    getint(ip);

    return 0;
}

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch())) 
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    
    sign = (c == 1) ? 1 : -1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
} 

// Decided this is a terrrible exercise.
