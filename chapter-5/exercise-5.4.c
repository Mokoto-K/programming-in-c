/*Write the function strend(s,t) which returns 1 if the string t occurs at the end of the */
/*string s, and zero otherwise.*/

#include <stdio.h>

int strend(char *s, char *t);

int main() {
    char a[] = "something";
    char b[] = "someone";
    char c[] = "thing";

    int t1 = strend(a, c);
    int t2 = strend(b, c);
    
    printf("%d\n", t1);
    printf("%d\n", t2);

    return 0;
}

int strend(char *s, char *t) {
    int i;
    
    // Run string t to the end, keeping track of length
    for (i = 0; *t != '\0'; i++)
        t++;

    // Run string s to the end
    while (*s != '\0')
        s++;

    // Wind back the last i amount of chars, if they don't match return 0, else 1
    while (i > 0) {
        i--, t--, s--;
        
        if (*s != *t)
            return 0;
    }

    return 1;  
}
