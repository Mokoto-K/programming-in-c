#include <stdio.h>

#define MAXLEN 5000

int getword(FILE *);

int main(int argc, char *argv[]) {
  
    int line = 1;
    char c;

    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        
        while ((c = fgetc(fp)) != EOF) {
            printf("%c", c);
        }
        :wq

        fclose(fp);
    }
    return 0;
}

/*int getword(FILE *fp) {*/
/*    char c;*/
/*    int i;*/
/**/
/*    while ((c = fgetc(fp)) != EOF)*/
/*        printf("%c", c);*/
/**/
/*    return c;*/
/*}*/
