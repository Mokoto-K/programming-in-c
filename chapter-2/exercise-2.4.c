#include <stdio.h>
#include <string.h>
#define MAX 200

void squeeze(char s1[], char s2[]);

int main() {
    char s1[MAX] = "mokoto koiyonagi";
    char s2[MAX] = "aeiou";
    
    printf("%s\n", s1);
    squeeze(s1, s2);
    printf("%s\n", s1);
    
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int k = 0;
    int state = 0;

    for (int i = 0; i < s1_len; ++i) {
        for (int j = 0; j < s2_len; ++j) {
            if (s2[j] != s1[i]) {
                state = 1;
            }
            else {
                state = 0;
                break;
            }
        }

        if (state) {
            s1[k++] = s1[i];
        }
        
        if (i == s1_len - 1) {
                s1[k] = '\0';
        }
    }
}

// s1 = poop
// s2 = soon
// squeeze(s1,s2)
// s1 = pp
