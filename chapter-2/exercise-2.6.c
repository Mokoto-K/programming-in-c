#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {

    int x = 85;
    int n = 4;
    int p = 2;
    int y = 31;
    
    printf("%d\n", setbits(x, p, n, y));
    return 0;
}

int setbits(int x, int p, int n, int y) {
    return (x & ~(((1 << n) - 1) << p)) | ((y & (1 << n) - 1) << p); 
}

