#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        }
        else {
            putchar(c);
            while ((c = getchar()) == ' ') {
                ;
            }
            putchar(c);
        }
    }
    return 0;
}
