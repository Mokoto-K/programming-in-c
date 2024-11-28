#include <stdio.h>

#define MAXLINE 2000
#define LIMIT 0

int my_getline(char line[], int maxline);
void copy(int count, char to[], char from[]);

int main() {
    int len;
    int counter;

    counter = 0;

    char line[MAXLINE];
    char collection[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > LIMIT + 1) {
            copy(counter, collection, line);
            counter = counter + len;
        }
    }
    printf("%s\n", collection);
    
       return 0;
}

int my_getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c != ' ' && c != '\t') {
            s[i] = c;
        }
        else {
            --i;
        }
    }
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void copy(int counter, char to[], char from[]) {
    int i;
    i = 0;
    while ((to[counter] = from[i]) != '\0') {
        ++counter;
        ++i;
    }
}
