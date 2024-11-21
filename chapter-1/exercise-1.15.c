#include <stdio.h>

float tempreature_converter(int x);

int main() {
    int input, choice;

    while ((choice = getchar()) != EOF) {
        printf("Press 'f' to convert to Farenheit, 'c' for Celcius or CTRL+D to exit\n");
        
        if (choice == 'c') {
            printf("Enter a Tempreature to convert\n");
            input = getchar(); 
            printf("%3.2f\n", tempreature_converter(input));
        }
        

        
    return 0;
}

float tempreature_converter(int celcius) {
    float f;

    f = 9.0 / 5.0 * celcius + 32;

    return f;
}

    
