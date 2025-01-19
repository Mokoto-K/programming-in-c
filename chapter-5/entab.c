/*Writting this for chapter 5 exercise */

#include <stdio.h>

#define TAB 4

int main() {
    char c, d;
    int space_count, i, div= 0;

    while ((c = getchar()) != EOF) {
       
        // if the input is a space
        if (c == ' '){
            // increment the space counter by one
            space_count++;
            // check if the next input is also a space 
            if ((d = getchar()) == ' ') {
                // increment again
                space_count++;
                // keep incrementing until the input is not a space 
                for (; (d = getchar()) == ' '; space_count++) 
                    div = space_count / TAB;


            }
        }
    }
    return 0;
}
