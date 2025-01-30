#include <stdio.h>

#define MAXLINES 5000
#define MAXLEN 1000

void readlines(char **, int);
int mygetline(char *s, int n);

int main(int argc, char *argv[]) {
    char lines[MAXLINES][MAXLEN]; 
    int c, i;

   // This section in main is essentially readlines, i spent too long here
    // and it does what readlines would do, holy fuck this was hard.
    for (i = 0; (mygetline(lines[i], MAXLEN)) != 0; i++)
        ;   
    
    for (int j = 0; j < i; j++)
        printf("%s\n", lines[j]);

    return 0;
}

int mygetline(char *s, int n) {
    int c, i;

    for (i = 0; i < n && (c = getchar()) != '\n'; i++)
        s[i] = c;
    
    if (i > 1) {
        /*s[i++] = c;*/ //adds the space
        s[i] = '\0';
        /*printf("%s\n", s);*/
        return i;
    }
    else 
        return 0;
}
