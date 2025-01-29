#include <stdio.h>

#define MAXLINES 5000
#define MAXLEN 1000

void readlines(char **, int);
int mygetline(char *s, int n);

int main(int argc, char *argv[]) {
    char *lines[MAXLINES]; // makes me an array of 5000 pointers
    char **ptr = lines; // is a pointer that points to the first pointer in 

    lines[0] = "hello";
    lines[1] = "world";

    for (int i = 2; i > 0; i--) {
        printf("%s\n", *ptr);
        ptr++;
    }
    /*for (int i = 0; i < MAXLINES; i++) {*/
    /*    *lines[i] = i;*/
    /*    printf("%d, %c\n", i, *lines[i]); */
    /*}        */
    /*mygetline(lines[0], MAXLEN);*/
    /**/
    /*printf("%s\n", lines[0]);*/
    return 0;
}

int mygetline(char *s, int n) {
    int c, i;

    for (i = 0; i < n && (c = getchar()) != '\n'; i++)
        *s++ = c;
    
    return 1;
}
