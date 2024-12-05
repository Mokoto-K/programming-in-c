#include <stdio.h>

void check_syntax(char open, char close);

int main() {
    
    check_syntax('(', ')');
    check_syntax('[', ']');
    check_syntax('{', '}');
    check_syntax('"', '"');
    check_syntax('\'', '\'');

    return 0;
}

void check_syntax(char open, char close) {
    int c, count;
    count = 0;
    // Check each input char for any syntax input and balance out the pairs by
    // adding one if something is opened and minusing one if it is closed.
    while ((c = getchar()) != EOF) {
        if (c == open) {
            ++count;
        }
        else if (c == close) {
            --count;
        }
    }

    // Check each syntax pair for negative numbers, i.e they were closed but never open.
    if (count< 0) {
        count = count * -1;
    }
    
    // Print out each type of syntax and how many mismatched pairs exist.
    printf("Number of unmatched '%c': %d\n", open, count);
}
