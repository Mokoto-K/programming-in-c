#include <stdio.h>

int main() {
    float f;

    printf("Celcius to farenheit converter\n");
    printf("--------------------------------\n");

    for (int c = 0; c < 50; c = c+2) {
        f = 9.0/5.0 * c + 32;
        printf("%3d %3.2f \n", c, f);

    }
     return 0;
}
