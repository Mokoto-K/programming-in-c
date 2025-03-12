#include <stdio.h>

int lower(int x);

int main() {
    int x = 'A';

    printf("%c\n", lower(x));

    return 0;
}

int lower(int x) {
    return x < 97 ? x + 32 : x;
}

