#include <stdio.h>

int mystrend(char *, char *);

int main(int argc, char*argv[]) {
    char *s = "hello world";
    char *t = "orld";
    char *u = "boob";

    printf("Test one: %d answer: 1, Test 2: %d answer: 0\n", mystrend(s, t),
           mystrend(s, u));
    return 0;
}

int mystrend(char *s, char *t) {
    int i, j;

    for (i = 0; *t != '\0'; i++ , t++)
        ;

    for (j = 0; *s != '\0'; j++ , s++)
        ;

    while (*s-- == *t--) {
        if (i == 0) {
            // wind back the pointer of s for another comparison
            for (; j > 0; j-- , s--)
                ;
           return 1;
        }
        i--;
    }
    return 0;
}
