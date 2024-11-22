#include <stdio.h>

float celcius_converter(int x);
float farenheit_converter(int x);


int main() {
    int input, choice;

    printf("Press 'f' to convert to Farenheit, 'c' for Celcius or CTRL+D to exit\n");

    while ((choice = getchar()) != EOF) {
        
        if (choice == 'c') {
            printf("Enter a Tempreature to convert\n");
            printf("%3.2f\n", celcius_converter((input=getchar())));
        }
        
        else if (choice == 'f') {
            printf("Enter a Tempreature to convert to Farenheit\n");
            printf("%3.2f\n", farenheit_converter((input=getchar())));
        }

        else {
            printf("Not a valid option\n");
        }
    }
    return 0;
}

float celcius_converter(int celcius) {
    float f;

    f = 9.0 / 5.0 * celcius + 32;

    return f;
}

float farenheit_converter(int farenheit) {
    float c;

    c = 5.0 / 9.0 * (farenheit + 32);

    return c;
}    
