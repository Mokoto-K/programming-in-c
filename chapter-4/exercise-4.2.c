/*Extend atofd to handle scientific notation of the form 123.45e-6*/

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
    /*char s[] = "123.45e-6";*/
    char s[] = "123.45e-6";
    printf("%f\n", atof(s));

    return 0;
}

double atof(char s[]) {
    double val, power;
    int i, sign, exp_sign;
    int multi = 1;
    
    // Check for empty space before the float
    for (i = 0; isspace(s[i]); i++)
        ;

    // Check if there is a leading negative sign
    sign = (s[i] == '-') ? -1 : 1;
    
    // Increment i if there is a leading sign 
    if (s[i] == '+' || s[i] == '-')
        i++;
   
    // Deals with getting the int part of the float
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // Checks for the decimal
    if (s[i] == '.')
        i++;

    // Deal with the float part of the double
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    // Check for an e for exponential
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
    }

    // Get exponential sign
    exp_sign = (s[i] == '-') ? -1 : 1;

    // Iterate over sign
    if (s[i] == '+' || s[i] == '-') { 
        i++;
    }

    // add the right amount of zeros
    for (int j = 0; isdigit(s[i]) && j < (s[i] - '0'); j++) {
        multi *= 10;
    }
    
    if (exp_sign < 0) {
        return sign * val / power / multi;
    }
    else {
        return sign * val / power * multi;
    }
}
