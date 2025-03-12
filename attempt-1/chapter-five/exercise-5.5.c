/*Write version of the lib funcs, strncpy, strncatn strncmp, which operate on at*/
/*most n chars of theri argument strings, for ex, strncpy(s,t,n) copies at most */
/*n chars of t to s*/

#include <stdio.h>

void mystrncp(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

int main() {
    char s[] = "abcdefg";
    char t[] = "hijklmn";
    char s2[] = "abcdefg";
    char t2[] = "hijklmn";
    
    int n = 3;

    mystrncp(s,t,n);
    printf("s = %s t = %s\n", s, t);

    mystrncat(s2,t2,n);
    printf("s = %s t = %s\n", s, t);

    int c = mystrncmp(s,t,n);
    printf("%d\n", c);

    return 0;
}

void mystrncp(char *s, char *t, int n) {
    for (int i = 0; i < n; i++, s++, t++) {
        if (*t == '\0') 
            *s = '\0';
        else
            *s = *t;
    }
}

void mystrncat(char *s, char *t, int n) {
    while (*s != '\0')
        s++;
    
    for (int i = 0; i < n; i++, s++, t++)
        *s = *t;
    *s = '\0';
}


int mystrncmp(char *s, char *t, int n) {
    printf("%s %s\n", s, t);
    for (int i = 0; i < n; i++, s++, t++) {

        if (*s != *t) {
            return *s - *t;
        }
    }
    return 0;
}
