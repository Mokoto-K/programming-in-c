#include <stdio.h>

int main() {
    int c, bl, nl, tl;

    bl = nl = tl = 0;
    c = getchar();

    while ((c = getchar()) != EOF) {
        if (c == ' ') { 
            ++bl;
        }
        else if (c == '\t') {
            ++tl;
        }
        else if (c == '\n') {
            ++nl;
        }
    }
    printf("Blank spaces: %d, Tabs: %d, Lines: %d \n", bl, tl, nl);

    return 0;
}
