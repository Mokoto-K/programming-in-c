#include <stdio.h>
#include <string.h>

#define MAX 2000

void expand(char s1[], char s2[]);

int main() {
    char s1[] = "hello, can you type a-b for me real quick";
    char s2[MAX];

    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[]) {

    int i, j;
    int length = strlen(s1);

    for (i = 0; i < length; ++i) {
        if (i > 0 && i < (length - 1) && s1[i] == '-') {
            int prev = s1[i-1];
            if (prev == 'a' || prev == 'A' || prev == 0) {
                int next = s1[i+1];
                if (next == 'z' || next == 'Z' || next == 9) {
                    switch (prev) {
                        
                        case 'a':
                            for (int k = 0; k < 26; ++k) {
                                s2[j] = k + 97;
                                j++;
                            }
                            break;

                        case 'A':
                            for (int k = 0; k < 26; ++k) {
                                s2[j] = k + 65;
                                j++;
                            }
                            break;

                            
                        case 0:
                            for (int k = 0; k < 9; ++k) {
                                s2[j] = k - '0';
                                j++;
                            }
                            break;

                        default:
                            break;
                    }
                }
                else {
                    s2[i] = s2[j];
                    j++;
                }
            }
            else {
                s2[i] = s2[j];
                j++;
            }
        }
        else {
            s2[i] = s2[j];
            j++;
        }
    }
}
