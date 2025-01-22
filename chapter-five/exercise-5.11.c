/*Modify the programs entab and teab to accept a list of tab stops as arguments. */
/*Use the default tab settings if there are no arguments. */

#include <stdio.h>

#define TAB 8

int stoi(char *s);
int main(int argc, char *argv[]) {
    int c, spaces = 0, tab, colnum = 0;
    
    if (argc > 1)
        tab = stoi(*++argv); 
    else 
        tab = TAB;
    while ((c = getchar()) != EOF) {

        if (c == ' ')
            ++spaces;
        else if (c != '\n') {
            // Deal with the tabs first 
            while (spaces >=tab) {
                putchar('\t');
                spaces -= tab;
                colnum += tab; 
            }
            // Deal with the spaces 
            while (spaces > 0) {
                putchar(' ');
                --spaces;
                ++colnum;
            }

            putchar(c);
        }
        else 
            colnum = 0;
        }
            
    return 0;
}

int stoi(char *s) {
        int num = 0;

    for (int i = 0; s[i] != '\0'; i++) 
        num = 10 * num + (s[i] - '0');
        
    /*printf("%d\n", num);*/
    return num;
}
