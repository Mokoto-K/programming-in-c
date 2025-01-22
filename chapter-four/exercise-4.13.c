#include <stdio.h>

#define MAXLENGTH 100
static int i = 0;
static int j = 0;

void reverses(char s[], char c[]);

int main() {
    char s[] = "hello";
    char c[MAXLENGTH];

    reverses(s, c);
    printf("%s\n", c);
    return 0;
}

void reverses(char s[], char c[]) {

    if (s[i] != '\0') {
        i++;
        reverses(s, c);
    }

    i--;
    c[j] = s[i];
    if (i < 0) {
        c[j] = '\0';
    }
    j++;
}
