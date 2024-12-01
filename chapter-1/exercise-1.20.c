#include <stdio.h>

int main() {
    int c, colnum;

    colnum = 4;

    while ((c = getchar()) != EOF) {

        if (c == '\t') {
            for (int i = colnum; i >= 0; --i) {
                putchar(' ');
            }
        }
        else {
            putchar(c);
        }

        if (colnum > 0) {
            --colnum;
        }
        else {
            colnum = 4;
        }
    }
    return 0;
}
