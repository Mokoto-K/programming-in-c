/*Writing detab and entab again so jhat I can do the next exercise in chapter 5*/

#include <stdio.h>

#define TAB 4

int main() {
    char c;
    int i, j = 0;

    while ((c = getchar()) != EOF) {
        if (c != '\t') { 
            putchar(c);
            j++;
        }
        else {
            int spaces = TAB - (j % TAB);
            for (i = 0; i < spaces; i++) {
                putchar(' ');
                j++;
            }
        }
    }
return 0;
} 
