#include <stdio.h>

// Define the max length a line/string can be
#define MAX 2000

void escape(char s[], char t[]);
void capture(char s[], char t[]);

int main() {
    char s[MAX];
    char t[MAX];
    char c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        t[i] = c;
        i++;
    }
    capture(s, t);
    /*escape(s, t);*/
    printf("%s\n", s);
    return 0;
}

void escape(char s[], char t[]) {
    int i, j = 0;    
    for (i = 0; i < MAX; ++i) {
        switch (t[i]) {

            case '\n':
                s[j] = '\\';
                j++;
                s[j] = 'n'; 
                j++;
                break;

            case '\t':
                s[j] = '\\';
                j++;
                s[j] = 't'; 
                j++;
                break;

            default:
                s[j] = t[i];
                j++;
                break;
        }
    }
}

// Logic is a little screwy, but cbf tinkering with this at the moment, the main
// exercise is done.
/*void capture(char s[], char t[]) {*/
/*    int i, j = 0;    */
/*    for (i = 0; i < MAX; ++i) {*/
/*        switch (t[i]) {*/
/**/
/*            case '\\':*/
/*                switch (t[i+1]) {*/
/**/
/*                    case '\n':*/
/*                        s[j] = '\n';*/
/*                        j++;*/
/*                        break;*/
/**/
/*                    case '\t':*/
/*                        s[j] = '\t';*/
/*                        j++;*/
/*                        break;*/
/**/
/*                    default:*/
/*                        s[j] = t[i];*/
/*                        j++;*/
/*                        break;*/
/*                }*/
/**/
/*            default:*/
/*                s[j] = t[i];*/
/*                j++;*/
/*                 break;*/
/*        }*/
/*    }*/
/**/
/*}*/


