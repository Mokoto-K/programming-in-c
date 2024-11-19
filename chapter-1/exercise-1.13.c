#include <stdio.h>

#define MAXLENGTH 9
#define MAXWORDS 99
#define IN 0
#define OUT 1

int main() {
    int words[MAXWORDS] = {0};
    int ch, wordlength, state, i;
    wordlength = i = 0;
    state = OUT;    

    while ((ch = getchar()) != EOF) {
        if (ch != ' ' && ch != '\t' && ch != '\n') {
            ++wordlength;
            state = IN;
        }
        else if (state) {
            words[i] = wordlength;
            ++i;
            wordlength = 0;
            state = OUT;
        }
    }
    for (int x = 0; x < i; ++x) {
        for (int y = 1; y < words[x]; ++y) {
            printf("x");
        }
        putchar('\n');
    }
   return 0;
}
