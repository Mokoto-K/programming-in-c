#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int ch;
    int state = OUT;

    while ((ch = getchar()) != EOF) {
        if (ch != ' ' && ch != '\t' && ch != '\n') {
            putchar(ch);
            state = IN;    
        }
        else if (state) {
            putchar('\n');
            state = OUT;
        }
    } 
    return 0;
}

