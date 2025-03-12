#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

// If the stack isnt full, then push the value onto it and increment position
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else 
        printf("error: stack full, can't push %g\n", f);
}

// If the stack isnt empty then get the last value place in the double array
double pop(void) {
    if (sp > 0)
        return val[--sp]; 
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
