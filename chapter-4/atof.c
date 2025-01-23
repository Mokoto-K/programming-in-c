#include <ctype.h>

double atof(char *s) {

    double val = 0.0, power = 1.0, epx = 0.0, num;
    int i, sign;

    // Check if we have a space and skip until we dont 
    while (isspace(*s))
        s++;

    // peep the sign of the float, if one exists
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;

    // Create the float from the string
    while (isdigit(*s)) {
        val = 10.0 * val + (*s - '0');
        s++;
    }

    // Check for a decimal point, skip over  it 
    if (*s == '.')
        s++;

    // Get what comes after the decimal 
    while (isdigit(*s)) {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
        s++;
    }

    // This is now our number
    num = sign * val / power; 
    
    // Expansion for scientific notation 
    if (*s == 'e' || *s == 'E')
        s++;

    if (*s == '-') {
        s++;
        while (isdigit(*s)) {
            epx = 10.0 * epx + (*s - '0');
            s++;
        }
        for (int j = 0; j < epx; j++)
            num /= 10;
     }
    else {
        while (isdigit(*s)) {
            epx = 10.0 * epx + (*s - '0');
            s++;
        }
        for (int j = 0; j < epx; j++)
            num *= 10;
    }
    return num;
}
