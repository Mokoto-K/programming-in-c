#include <stdio.h>

int main() {
    int c, d;

    while ((c = getchar()) != EOF) {

        // If the char is equal to a forward slash
        if (c == '/') {

            // Check what the next char is
            c = getchar();
            
            // If it's also a forward slash
            if (c == '/') {
                // Ignore everything until there is a new line
                while ((c = getchar()) != '\n') {
                    ;
                } 
            }

            // If it's a star
            else if (c == '*') {
                // Ignore everything until there is a star & forward slash next to each other
                while ((c = getchar()) != '*' && (d = getchar()) != '/' ) {
                    ;
                }
            }

            // Else just put the char to the output
            else {
            putchar(c);
            }
        }
        
        // Else just put the char to the output
        else {
            putchar(c);
        }
    }
    return 0;
}
