#include <stdio.h>

#define TAB 4

int main() {
    int c, spaces, colnum;
    spaces = colnum = 0;

    while ((c = getchar()) != EOF) {

        if (c == ' ') {
            ++spaces;
        }
        else if (c != '\n') {
        
            while (spaces >= TAB) {
                putchar('\t');
                spaces -= TAB;
                colnum += TAB;
            }

            while (spaces > 0) {
                putchar(' ');
                --spaces;
                ++colnum;
            }

            putchar(c);
        }
        else {
            colnum = 0;
        }
    }
    return 0; 
}
