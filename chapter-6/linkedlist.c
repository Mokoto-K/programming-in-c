#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createnode(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Error: not enough memory to make a new entry");
        return NULL;
    }

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

void insertbeginning(struct node **head, int value) {
    struct node *newnode = createnode(value);

    if (newnode == NULL) 
        return;

    newnode->next = *head;
    *head = newnode;
}

void intsertend(struct node **head, int value) {
    struct node *newnode = createnode(value);

    if (newnode == NULL)
        return;

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL) 
        current = current->next;

    current->next = newnode;
}

void deletenode(struct node **head, int value) {
    if (*head = NULL)
        return;

    struct node *current = *head;
    struct node *previous = NULL;

    if (current != NULL && current->data == value) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    previous->next = current->next;
    free(current);
}

void reverselist(struct node **head) {
    struct node *current = *head;
    struct node *next = NULL;
    struct node *prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void printlist(struct node *head) {
    struct node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void freelist(struct node *head) {
    struct node *current = head;
    struct node *nextnode;

    while (current != NULL) {
        nextnode = current->next;
        free(current);
        current = nextnode;
    }
}

int main() {
    struct node *head = NULL;

    insertbeginning(&head, 10);
    insertbeginning(&head, 20);
    insertbeginning(&head, 30);
    insertbeginning(&head, 40);
    insertbeginning(&head, 50);
    insertbeginning(&head, 60);
    
    printf("Linked List: ");
    printlist(head);

    return 0;
}
