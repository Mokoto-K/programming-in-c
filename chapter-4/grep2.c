#include <stdio.h>

#define MAXLENGTH 1000

int nextline(char *);
int match_pattern(char *, char *);


int main() {
    char *pattern = "ould";
    char line[MAXLENGTH];

    while (nextline(line) > 0) 
        printf("%s\n", line);
        
    return 0;
}

int nextline(char *input) {
    int c, i;
    c = i = 0;

    while ((c = getchar()) != '\n') {
        if (c == EOF)  // pointless as it will shoot us outta the program anyway
            return -1;
        input[i] = c;
        i++;
    }
    return 1;
}
    
int match_pattern(char *line, char *pattern) {
    
    for (int i = 0; i < MAXLENGTH; i++)
}
