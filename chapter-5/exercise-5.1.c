/*As written, getint treats a + or a - not followed by a digit as a valid*/
/*representation of zero. Fix it to push such a character back on the input.*/

#include <stdio.h>
#include <ctype.h>

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch())) 
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        unget(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int next = getch();
        if (!isdigit(next))
            unget(next)
            unget(c);
            return next;
    }
}

/*Apparently this solution is fine, but i have problems with the logic of all of */
/*this, it just doesnt really make sense to me to push back the character and the */
/*+ or - sign since that will literally just create an infinite loop of reading*/
/*+ or - first again, getting the next char, its not a digit, ungetting both*/
/*going again, repeat. Im uncomfortable with this solution and with this exercise,*/
/*I feel like im missing the greater point.*/
