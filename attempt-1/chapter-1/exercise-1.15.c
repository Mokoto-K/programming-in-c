#include <stdio.h>

float celcius_converter(int x);
float farenheit_converter(int x);


int main() {
    int input, choice, answer;

    printf("Press 'f' to convert to Farenheit, 'c' for Celcius or CTRL+D to exit\n");

    while ((choice = getchar()) != EOF) {
        
        printf("Enter a Tempreature to convert\n");

        input = getchar();
        
        if (choice == 'c') {
            answer = celcius_converter(input);
        }
        
        else if (choice == 'f') {
            answer = farenheit_converter(input);
        }

        else {
            printf("Not a valid option\n");
        }
        
        printf("%3.2f\n", answer);
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

