/*Write the function strrindex(s, t), which returns the position of the right*/
/*most ocurrence of t in s, or -1 if there is none.*/

#include <stdio.h>

#define MAX 1000

int strrindex(char s[], char t);

int main() {
    char s[] = "The poop that went poop in the soup, it tru.";
    char t = 'p';

    int position = strrindex(s, t);

    if (position > -1) {
        printf("%c's last appearance is at index %d\n", t, position);
    }
    else {
        printf("%c doesnt appear in the supplied string\n", t);
    }

return 0;
}

int strrindex(char s[], char t) {
    int i, index, exists = 0;
    
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == t) {
            index = i;
            exists = 1;
        }
    }

    if (exists > 0) {
        return index;
    }
    else {
        return -1;
    }
}
