#include <stdio.h>

#define MAXWORDS 100
#define IN 1
#define OUT 0

int main() {
    int words[MAXWORDS] = {0};

    int c, letters, state, i, maxlength;
    state = OUT;
    letters = i = maxlength = 0;

    printf("Type whatever you would like, when you are done hit CTRL + D to finished the program\n");

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            ++letters;
            state = IN;
        } 
        else if (state) {
            if (letters > maxlength) {
                maxlength = letters;
            }
            words[i] = letters;
            letters = 0;
            ++i;
            state = OUT;
        }
    }

    // Catch the case where EOF happens but no space or new line has been pressed
    if (state) {
        if (letters > maxlength) {
            maxlength = letters;
        }
        words[i] = letters;
        ++i;
    }



    printf("\n---- Horizontal Histogram ----\n");
    for (int y = 0; y < i; ++y) {
        for (int x = 0; x < words[y]; ++x) {
                printf("x");
        }
        if (words[y] != 0) {
            printf("\n");
        }
    }

    printf("\n---- Vertical Histogram ----\n");
    while (maxlength > 0) {
        for (int y = 0; y <= i; ++y) {
            if (words[y] < maxlength) {
                printf("   ");
            } else {
                printf(" x ");
            }
        }
        --maxlength;
        printf("\n");  
    }

    return 0;
}

