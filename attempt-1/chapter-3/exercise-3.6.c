
/*Exercise 3-6. Write a version of itoa that accepts three arguments instead of
two. The third agrument is a min field width; the converted number must be 
padded with blanks on the left if needed to make it wide enough*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char s[]);
void itoa(int n, char s[], int b);

int main() {

    int n = 4444;
    char s[199];
    int b = 8;
    itoa(n, s, b);
    printf("%s\n", s);

    return 0;
}

void itoa(int n, char s[], int b) {

    int i;
    int sign = n;

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    
    if (sign < 0)
        s[i++] = '-';

    while (b > i) {
        s[i++] = ' ';
    }
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
