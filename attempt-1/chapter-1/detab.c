#include <stdio.h>

#define TAB 4

int main() {
    int c, colnum, diff;

    colnum = 0;

    while ((c = getchar()) != EOF) {

        if (c == '\t') {
            
            if (TAB > colnum) {
                diff = TAB - colnum;
            }
            else {
                diff = colnum - TAB;
                while (diff > 4) {
                    diff = diff - TAB;
                }
                diff = TAB - diff;
            }
        
            for (int i = diff; i > 0; --i) {
                putchar(' ');
                ++colnum;
            }
        }
        else if (c != '\n') {
            putchar(c);
            ++colnum;
        }
        else {
            colnum = 0;
        }
    }
    return 0;
}
