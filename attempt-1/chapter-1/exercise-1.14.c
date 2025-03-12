#include <stdio.h>

#define ASCII 26

int main() {
    int chars[ASCII] = {0};
    char c;
    
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
        
        if (c >= 'a' && c <= 'z') {
            ++chars[c-'a'];
        }
    }
    
    printf("\nHorizontal Histogram of character Frequency\n");
    for (int x = 0; x < ASCII; ++x) {
        printf("%c| ", 'a' + x);
        for (int y = 0; y < chars[x]; ++y) {
            printf("x");
        }
        printf("\n");
    }

    return 0;
}
