/*write the program tail which prints the last n lines of its input. By default*/
/*n is 10, let us say, but it can be changed by an opotional argument so that */
/*tail -n prints the last n lines.*/

#include <stdio.h>

#define MAXSIZE 100
#define MAXLINES 3

int myline(char *sa);

int main(int argc, char *argv[]) {
    int i, c;
    char *pl[MAXSIZE];

    // Get all the lines and store then in the array of pointers 
    while ((c = myline(*pl)) > 2)
        /*printf("seg 2 %d\n", c);*/
        ;
    // Wind the array back to point x elements back 
    /*for (i = 0; i < MAXLINES; (*pl)--)*/
        /*;*/

    // Winf the array forward the same amount printing each string its pointing to
    /*for (;i > 0; (*pl)++) */
        /*printf("%s\n", *pl);*/
    
    return 0;
}

int myline(char *pl) {
    int c, i = 0;
    char *line;

    // While the input isnt EOF or a new line, continue to add the char to the string 
    while ((c = getchar()) != EOF && c != '\n'){
        line[i] = c;
        pl[i] = c;
        i++;
        printf("index: %d char %s\n", i, pl);
    }

    // If the input is a new line, add it and the 0 char to the end of the string 
    if (c == '\n')  {
        line[i++] = '\n';
        line[i++] = '\0';
    }
    // increment the array of pointers by one and add the string to the array 
    /**pl = line;*/
    /*printf("%s \n", pl);*/
    // return whatever it is c finished on.
    return i;
}
