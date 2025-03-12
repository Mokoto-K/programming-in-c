/*Write getfloat, the floating-point analog of getint. What type does getfloat*/
/*return as its function value?*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int);
//int getfloat(int *);

int getfloat(int *pn) {

    int c, sign;

    // Deal with blank chars
    while (isspace(c = getch())) 
        ;

    // Deal with non numbers or important chars like + - EOF
    if (!isdigit(c) && c != '-' && c != '+' && c != EOF) {
        ungetch(c);
        return c;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '-' || c == '+')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF) 
        ungetch(c);
    return c;
} 

int main() {
    int n, array[SIZE], getfloat(int *);

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    for (n = 0; n < SIZE; n++)
        printf("%d\n", array[n]);

    return 0;
}

int buf[SIZE];
int bufp = 0;

int getch(void) {
    
    return (bufp > 0) ? buf[--bufp] : getchar();

}

void ungetch(int c) {

    if (bufp >= SIZE)
        printf("ungetch: To many charaters\n");
    else
        buf[bufp++] = c;

}
