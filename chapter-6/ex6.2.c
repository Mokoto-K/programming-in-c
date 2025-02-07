#include <stdio.h>

#define MAXLEN 5000

int getword(FILE *);

int main(int argc, char *argv[]) {
   
    char c;


    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        
        while ((c = getword(fp)) != EOF) 
            ; 

        fclose(fp);
    }
    return 0;
}

int getword(FILE *fp) {
    char c;
    int i;

    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);

    return c;
}
