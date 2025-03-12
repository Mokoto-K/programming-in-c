#include <stdio.h>

int main() {
    
    double f, c;
    f = c = 0;

    for (; f < 301; f+=20)
        printf("%3.2f\t%6.2f\n", f, c = (5.0 / 9.0) * (f - 32));
   /*while (f < 300) {*/
   /*     c = (5.0 / 9) * (f - 32);*/
   /*     printf("%3.2f \t %3.2f\n", f, c);*/
   /*     f += 20;*/
   /* }*/

    return 0;
}


        

