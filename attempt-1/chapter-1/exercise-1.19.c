#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);
void reverse(int len, char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char reversed[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        reverse(len, reversed, line);
        printf("%s\n", reversed);
    }
    
    return 0;
}

int my_getline(char s[], int limit) {
    int c, i;
                                                                            
    for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i) {
         s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(int len, char to[], char from[]) {
    int j = 0;

    for (int i = len - 2; i >= 0; i--) {
        to[j] = from[i];
        j++;
    }
}
