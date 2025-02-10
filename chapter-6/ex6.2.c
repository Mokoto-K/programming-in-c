#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 5000

struct node {
    char *word;
    int group;
    struct node *next;
};

struct node *createnode(char *word){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));  

    if (newnode == NULL) {
        printf("Error: Not enough memory to add a new node");
        return NULL;
    } 

    newnode->word = word;
    newnode->next = NULL;

    return newnode;
}

int getword(FILE *);

int main(int argc, char *argv[]) {
  
    int line = 1;
    char c;

    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        
        /*getword(fp);*/
        while ((c = fgetc(fp)) != EOF) {
            printf("%c", c);
        }

        fclose(fp);
    }
    return 0;
}

int getword(FILE *fp) {
    char c;
    int i;
    char *temp;

    for (i = 0; (c = fgetc(fp)) != EOF; i++) {
        if (c != '\n')
            temp[i] = c;
        else {
         createnode(temp);
         temp = "";
         i = 0;
        }

    return c;
}


/*Exercise 1: Variable Name Grouping*/
/*Objective: Write a program that reads a C program and prints variable names 
in alphabetical order, grouping them based on the first 6 characters being the
same, but different somewhere after that.*/
/**/
/*How structs and memory fit in: You'll need to use a struct to represent each 
variable. The struct can contain fields for the variable name and maybe a count
(for grouping).*/
/*Steps:*/
/*Read in the C code from a file.*/
/*Skip over comments and strings.*/
/*Parse each word to check if it’s a variable.*/
/*Store and group the variable names based on the first 6 characters 
(a char[7] array can be useful here).*/
/*Sort the groups alphabetically and print them.*/
/*You might use a linked list or an array of structs to store the variable names 
and their counts.*/
