#include <stdio.h>

int invert(int x, int p, int n);

int main() {
    int x = 32;
    int p = 2;
    int n = 3;

    printf("%d\n", invert(x, p, n));

    return 0;
}

int invert(int x, int p, int n) {
    return (x & ~(((1 << n) - 1) << p)) | (~x & (((1 << n) - 1) << p));
}
