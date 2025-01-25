// Convert a number to a string using recursion

#include <stdio.h>

void itoa(char *, int *, int n);

int main(int argc, char *argv[]) {
    char s[20];
    int idx = 0;
    int num = 123;

    itoa(s, &idx, num);
    idx = 0;
    printf("%s\n", s);

    return 0;
}

void itoa(char *s, int *idx, int n) {

    if (n < 0) 
        s[(*idx)++] = '-';
 
    if (n / 10) 
        itoa(s, idx, n / 10);
    s[(*idx)++] = n % 10 + '0'; 
}
