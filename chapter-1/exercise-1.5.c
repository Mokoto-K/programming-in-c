#include <stdio.h>

int main() {
    float c;

    printf("Farenheit to C converter\n");
    printf("--------------------------\n");

    for (int f = 300; f > -1; f = f - 20) {
        c = 5.0/9.0 * f - 32;
        printf("%3d %3.2f\n", f, c);
    }
    return 0;
}

