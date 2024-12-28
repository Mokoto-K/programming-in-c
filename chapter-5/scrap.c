#include <stdio.h>

void swap(int *a, int *b);

int main() {

    int x = 1;
    int y = 2;
    int z[10];
    int *ip, *iq;

    printf("x = %d | y = %d\n", x, y);
    swap(&x, &y);
    printf("x = %d | y = %d\n", x, y);

    return 0;
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
