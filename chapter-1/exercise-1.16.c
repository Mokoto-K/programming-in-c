#include <stdio.h>

#define MAXLINE 1010

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
        else if (len > MAXLINE) {
            printf("Long boyt");
        }
    }

    if (max > 0) {
        printf("Number of chars: %d, - %s\n", max - 1, longest);
    }
    return 0;
}

int my_getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

