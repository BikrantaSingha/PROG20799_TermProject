/* 
main.c
authors: Bikranta Singha, Harshitbhai Patel, Thinh Quach
date created: 20th July, 2022
date modified: 23rd July, 2022
main.c file for group 8's term project for PROG20799 class 91692
house listings from mls being used to implement 3 different data structures:
stack, queue, and binary tree
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node {
	int id;
	char address[50];
	int price;
	struct Node * nextPtr;
};

struct TreeNode {
	struct TreeNode * leftPtr;
	int id;
	char address[50];
	int price;
	struct TreeNode * rightPtr;
};

typedef struct Node Node;
typedef Node * NodePtr;
typedef struct TreeNode TreeNode;
typedef TreeNode *TreeNodePtr;

//NodePtr *nodePtr, char * address
void push(NodePtr * stack, int id, char * address, int price);
void pop(NodePtr * stack);
void top(NodePtr stack);
void printStack(NodePtr stack);


void main(int argc, char *argv[]) {
	NodePtr root = (NodePtr)malloc(sizeof(Node));
	strcpy(root -> address, "1 34 Aa drive, Toronto");
	root -> id = 1;
	root -> price = 3;
	root -> nextPtr = NULL;
	
	/*testing stack operations
	top(root);
	push(&root, 2, "2 45 Bb drive, Mississauga", 45);
	top(root);
	pop(&root);
	top(root);
	push(&root, 2, "2 45 Bb drive, Mississauga", 45);
	push(&root, 2, "2 45 Bb drive, Mississauga", 45);
	push(&root, 2, "2 45 Bb drive, Mississauga", 45);
	push(&root, 2, "2 45 Bb drive, Mississauga", 45);
	printStack(root);
	*/
}


//stack operations
void push(NodePtr * stack, int id, char * address, int price){
	NodePtr root = (NodePtr)malloc(sizeof(Node));
	root -> id = id;
	strcpy(root -> address, address);
	root -> price = price;
	root -> nextPtr = *stack;
	(*stack) = root;
}

void pop(NodePtr * stack){
	if(*stack != NULL){
		printf("\nListing popped: \nid: %d \naddress: %s \nprice: %d", (*stack)->id, (*stack)->address, (*stack)->price);
		NodePtr tempPtr = *stack;
		*stack = (*stack) -> nextPtr;
		free(tempPtr);
	} else {
		printf("\nNo listing popped. The stack is empty.");
	}
}


void top(NodePtr stack){
	if(stack != NULL){
		printf("\nTop house listing: \nid: %d \naddress: %s \nprice: %d", stack->id, stack->address, stack->price);
	} else {
		printf("\nNo listings found. The stack is empty.");
	}
}

void printStack(NodePtr stack){
	if(stack == NULL){
		printf("\nNo listings to print. The stack is empty.");
	} else if(stack->nextPtr == NULL) {
		printf("\n\nid: %d \naddress: %s \nprice: %d", stack->id, stack->address, stack->price);	
	} else {
		printf("\n\nid: %d \naddress: %s \nprice: %d", stack->id, stack->address, stack->price);
		printStack(stack->nextPtr);
	}
}
//queue operations


//tree operations