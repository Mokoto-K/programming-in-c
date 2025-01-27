#include <stdio.h>

#define MAX 100

int sp = 0;
int buff[MAX];

int getch(void) {
    return (sp > 0) ? buff[sp--] : getchar();
    }

void ungetch(int n) {
    if (sp < MAX)
        buff[sp++] = n;
    else 
        printf("ungetch error, the buffer is full");
}

