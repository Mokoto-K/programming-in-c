
/*Exercise 3-4. In a two's complement number representation, our version of itoa*/
/*does not handle the largest negative number, that is, the value of a equal to - */
/*(2wordsize-l). Explain why not. Modify it to print that value correctly, */
/*regardless of the machine on which it runs. O*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main() {

    int n = -2147483648;
    char s[199];

    itoa(n, s);
    printf("%s\n", s);

    return 0;
}

void itoa(int n, char s[]) {

    int i;
    int sign = n;

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';
    reverse(s);
}

void reverse(char s[]) {

    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
