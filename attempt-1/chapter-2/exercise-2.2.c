#include <stdio.h>

#define ON 1
#define OFF 0

int main() {
    int lim = 100;
    int i = 0;
    int state = ON;
    int c;

    while (state) {
        if (i < lim-1) {
            c = getchar();

            if (c != '\n') {
                if (c != EOF) {
                    putchar(c);
                }
                else {
                    state = OFF;
                }
            }
            else {
                state = OFF;
            }
        }
        else {
            state = OFF;
        }

        ++i;
    }
    return 0;
} 
