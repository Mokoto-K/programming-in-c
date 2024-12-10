#include <stdio.h>

int atoi(char hex[]);

int main() {
    int h;
    char input[5] = "0xf1";
    h = atoi(input);
    printf("%d\n", h);
    return 0;
}

int atoi(char s[]) {
    int i, n;

    n = 0;
    for (i=0; s[i] >= '0' && s[i] <= '9'; ++i) {
         n = 10 * n + (s[i] - '0');
    }
    return n;
}
