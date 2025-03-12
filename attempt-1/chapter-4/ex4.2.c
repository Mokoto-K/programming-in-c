#include <stdio.h>

double atof(char n[]);

int main(int argc, char *argv[]) {
    double s;
     
    if (argc > 1)
        s = atof(argv[1]);
    else 
        s = atof("123.45");

    printf("%f\n", s);
    return 0;
}

