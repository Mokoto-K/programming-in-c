#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5000

struct node{
    char *word;
    int line_num[MAX];
    struct node *next;    
};

struct node *createnode(char *value, int line) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));    

    if (newnode == NULL)
        printf("Error: not enough memory to make a new node");

    newnode->word = value;
    newnode->line_num[0] = line; //This will cause a problem
    newnode->next = NULL;

    return newnode;
}
    
void insertnode(struct node **head, char *value, int line) {
    struct node *newnode = createnode(value, line);
    printf("1 %s\n", value); 
    if (newnode == NULL)
        return;

    printf("2 %s\n", value); 
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    printf("3 %s\n", value); 
    int cond = 0;
    struct node *current = *head;
    struct node *onebefore = NULL;
    while ((cond = strcmp(current->word, newnode->word)) < 0) { // This might also cause problems
        onebefore = current;
        current = current->next; 
    }
   
    printf("4 We get here 4"); 
    onebefore->next = newnode;
    newnode->next = current;
}
    
void printlist(struct node *head) {
    struct node *current = head;

    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

char *mygetword(FILE *);

int main(int argc, char *argv[]) {
    char c;
    FILE *fp = fopen(argv[1], "r");
    char word[MAX];
    int line = 0;

    struct node *head = NULL;
    while (mygetword(fp) != EOF) {

        /*if (c =='\n') */
        /*    line += line + 1; */
        /**/
        /*if (c == ' ') {*/
        /*    insertnode(&head, word, line);*/
        /*} */
    }
    /*printlist(head); */
    return 0;
}

char *mygetword(FILE *fp) {
    char c;
    char word[MAX];

    for(int i = 0; (c = fgetc(fp)) != ' '; i++) {
        word[i] = c; 
    }
    return word;
}




/*Exercise 2: Cross-referencer*/
/*Objective: Write a program that reads a document and prints a list of all words,*/
/*along with the line numbers on which they occur. Exclude common words like "the," */
/*"and," etc.*/
/**/
/*How structs and memory fit in: You'll need a struct to store each word and the */
/*line numbers it appears on.*/
/*Steps:*/
/*Read the document line by line.*/
/*Use getword (or fscanf) to extract words.*/
/*For each word, store it in a struct with a list of line numbers */
/*(a linked list of integers or a dynamic array could be used here).*/
/*Ignore "noise words" by checking against a predefined list.*/
/*Print each word and its associated line numbers.*/
/*You'll likely need to use malloc to allocate space for the word structs and */
/*their line numbers dynamically.*/
