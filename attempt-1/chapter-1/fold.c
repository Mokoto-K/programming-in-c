#include <stdio.h>

// Giga variables to limit the line and column lenght
#define MAX 2000
#define COLUMNLENGTH 10

int get_line(char line[], int maxline);

int main() {
    char line[MAX];
    int len, colnum = 0;

    // Get the char array and it's length by calling the get_line func
    while ((len = get_line(line, MAX)) > 0) {
        // Iterate over each char in the array up to its full length
        for (int i = 0; i < len; ++i) {
            ++colnum;

            // If the column number tracker is less than the allowed length
            if (colnum < COLUMNLENGTH) {
                putchar(line[i]);    // Put the input in the stdout
                
            }
            else {
                // If the current char isnt a blank
                if (line[i] != ' ') {
                    // and the one before that wasnt a blank
                    if (line[i-1] != ' ') {
                        // It's a word, so split it with a - and cont next line
                        putchar('-');
                        putchar('\n');
                        putchar(line[i]);
                    } 
                    // Otherwise it's the start of a new world, goto next line
                    else {
                        putchar('\n');
                        putchar(line[i]);
                    }
                }
                // and if the current char is a blank, then just go to next line
                else {
                    putchar('\n');
                }
                // reset the column length for the next line
                colnum = 0;
            }
        }
    } 
    return 0;
}

int get_line(char line[], int lim) {
    int c, i;
    // Iterate over user input until they enter a new line
    for (i = 0; i < lim-1 && (c = getchar()) != '\n'; ++i) {
        line[i] = c;
    }
    // add that new line to the char array and increment the index one last time
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    // Add the univeral c char to signal 0 to the char array
    line[i] = '\0';

    return i;
}

