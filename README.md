Singly Linked Lists

Testing Directory 

Purpose: This directory is designated for testing purposes.
Header File 

lists.h: This header file comprises definitions and prototypes for all types and functions developed for the project.
Type/File Definitions Prototypes

Structure list_s: This structure holds members:
char *str
unsigned int len
struct list_s *next
Type Alias list_t: This typedef is defined as struct list_s.
Task Descriptions

Task 0: Print List

File: 0-print_list.c
Description: This C function is responsible for printing all elements within a list_t list.
If the str member is NULL, the function displays [0] (nil).
Task 1: List Length

File: 1-list_len.c
Description: This C function calculates and returns the count of elements in a linked list_t list.
Task 2: Add Node

File: 2-add_node.c
Description: This C function appends a new node at the beginning of a list_t list.
In case of failure, it returns NULL.
Otherwise, it provides the address of the new element.
Task 3: Add Node at the End

File: 3-add_node_end.c
Description: This C function appends a new node at the end of a linked list_t list.
If the function encounters an error, it returns NULL.
Otherwise, it furnishes the address of the new element.
Task 4: Free List

File: 4-free_list.c
Description: This C function is responsible for releasing memory occupied by a list_t list.
Task 5: The Hare and the Tortoise

File: 100-first.c
Description: Prior to the main function execution, this C function prints the lines:
"You're beat! and yet, you must allow,"
"I bore my house upon my back!"
Task 6: Real Programmers and Assembly Code

File: 101-hello_holberton.asm
Description: This 64-bit assembly program employs the printf function without interrupts to print the line "Hello, Holberton" followed by a newline.

