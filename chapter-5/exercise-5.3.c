/*Write a pointer version of the function strcat that we showed in chapter 2.*/
/*strcat copies the string t to the end of s.*/

#include <stdio.h>

#define MAX 1000

void mystrcat(char *s, char *t);

int main() {
    char s[] = "abcdefghijkl";
    char t[] = "mnopqrstuvwxyz";

    mystrcat(s, t);
    printf("%s\n", s);

    return 0;
}

void mystrcat(char *s, char *t) {
    while (*s != '\0') {
        s++;
    }
    
    while ((*s++ = *t++))
        ;
}

/*void strcat(char s[], char t[]) {*/
/*    int i, j;*/
/**/
/*    i = j = 0;*/
/**/
/*    while (s[i] != '\0') */
/*        i++;*/
/*    while ((s[i++] = t[j++]) != '\0')*/
/*        ;*/
/*}*/


