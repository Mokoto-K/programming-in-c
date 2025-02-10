Exercise 2: Cross-referencer
Objective: Write a program that reads a document and prints a list of all words, along with the line numbers on which they occur. Exclude common words like "the," "and," etc.

How structs and memory fit in: You'll need a struct to store each word and the line numbers it appears on.
Steps:
Read the document line by line.
Use getword (or fscanf) to extract words.
For each word, store it in a struct with a list of line numbers (a linked list of integers or a dynamic array could be used here).
Ignore "noise words" by checking against a predefined list.
Print each word and its associated line numbers.
You'll likely need to use malloc to allocate space for the word structs and their line numbers dynamically.
