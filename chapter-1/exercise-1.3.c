#include <stdio.h>

int main() {
    float c;

    printf("Farenheit to celcius converter\n");
    printf("------------------------------\n");

    for(float f=0; f < 140; f = f + 10) {
        c = (5.0/9.0) * f - 32;
        printf("%3.0f %3.2f\n", f, c);
    }
    return 0;
}

