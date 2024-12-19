
/*Exercise 3-5. Write a function itob(n,s,b) that converts the iteger n into a
base b character representation in the string s. In particular, itob(n,s,16) 
formats n as a hexidecimal integer in s.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main() {

    int n = 31;
    char s[199];
    int b = 16;

    itob(n, s, b);
    printf("%s\n", s);

    return 0;
}

void itob(int n, char s[], int b) {

    int i;
    int sign = n;
    int mod;

    i = 0;
    do {
        mod = abs(n % b);
        s[i++] = (mod < 9) ? mod + '0' : mod + 55;
    } while ((n /= b) != 0);

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
