#include <stdio.h>

#define MAXLENGTH 200

int main() {
    FILE *file, *output;
    int c;
    char file_name[20], file_line[MAXLENGTH], processed_line[MAXLENGTH];

    // Get user to input the file they want to remove comments from 
    for (int i = 0; i < 20 && (c = getchar()) != '\n'; ++i) {
         file_name[i] = c;
    }

    // Open the file
    file = fopen(file_name, "r");

    // Check for NULL pointer error
    if (file == NULL) {
        printf("Could not find file\n");
        return 1;
    }

    printf("File was opened\n");

    
    // Clearing the file (this is for testing only, as to not dup the output)
    output = fopen("output.c", "w");
    fputs("", output);
    fclose(output);
    
    // Open a file to write the edited version of the program with no comments
    output = fopen("output.c", "a");

    while (fgets(file_line, MAXLENGTH, file) != NULL) {
        for (int i = 0; i < MAXLENGTH && file_line[i] != '/' && file_line[i+1] !=
            '/'; ++i) {
            processed_line[i] = file_line[i];
        }
         
        fputs(processed_line, output);
    }

    
    // Close the file
    fclose(file);
    fclose(output);
    return 0;
}
