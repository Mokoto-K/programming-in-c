#include <stdio.h>

#define MAXSIZE 100

int strrindex(char *s, char t);

int main(int argc, char *argv[]) {
    int c;
    char s[MAXSIZE];
    char *p = s;
    char t = 'a';

    // If there is an argument being passed in, set the char to search for as it.
    if (argc > 1) 
        t = *argv[1]; 
    
    for (int i = 0; (c = getchar()) != '\n'; i++)
       *p++ = c;

    printf("%d\n", strrindex(s, t));
    return 0;
}
