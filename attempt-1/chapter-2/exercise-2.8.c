#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
    unsigned x = 32;
    int n = 21;

    printf("%d\n", rightrot(x, n));

    return 0;
}

// Assuming an int is 32bits for this function
unsigned rightrot(unsigned x, int n) {
    
    while (n > 0) {
        if (x & 1) {
            x = x >> 1 | 1 << 31;
        }
        else {
            x = x >> 1;
        }
        n--;
    }
    return x;
}
