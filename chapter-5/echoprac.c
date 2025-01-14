#include <stdio.h>

int main(int argc, char *argv[]) {
    // V1 of echo
    /*int i;*/
    /**/
    /*for (i = 1; i < argc; i++)*/
    /*    printf("%s%s", argv[i], (i < argc - 1) ? " " : "");*/
    /*printf("\n");*/

    // V2 of echo
    /*while (--argc > 0) */
    /*    printf("%s%s", *++argv, (argc > 1) ? " " : "");*/
    /*printf("\n");*/
    // alternatively printf can be written like such
    while (--argc > 0) 
        printf((argc > 1) ? "%s " : "s", *++argv);
    printf("\n");        
    return 0;
}
