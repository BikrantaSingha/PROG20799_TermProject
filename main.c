/* 
main.c
authors: Bikranta Singha, Harshitbhai Patel, Thinh Quach
date created: 20th July, 2022
last modified: 23rd July, 2022
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

//stack definitions
void push(NodePtr * stack, int id, char * address, int price);
void pop(NodePtr * stack);
void top(NodePtr stack);
void printStack(NodePtr stack);

//queue definitions
void frontQ(NodePtr queue);
void backQ(NodePtr queue, NodePtr back);
NodePtr enqueue(NodePtr * queue, NodePtr back, int id, char * address, int price);
NodePtr dequeue(NodePtr * queue);
void printQ(NodePtr queue);

//tree definitions
void insertIntoTree(TreeNodePtr * tree, int id, char * address, int price);
void removeFromTree(TreeNodePtr * tree, int id);
TreeNodePtr binarySearchById(TreeNodePtr tree, int id);
void preOrder(TreeNodePtr tree);
void postOrder(TreeNodePtr tree);
void inOrder(TreeNodePtr tree);


void main(int argc, char *argv[]) {
	//node attributes
	int id;
	int price;
	char address[50];
	int i; //will be used for for loops
	
	//only to be used by queue operations
	NodePtr front = NULL;
	NodePtr back = NULL;
	
	//dummy addresses
	char * dummyAddresses[] = {
	"34 Aa Avenue, Toronto",
	"56 Bb Boulevard, Brampton",
	"701 Cc Circle Road, Mississauga",
	"9903 Dd Drive, Kitchner",
	"206 Ee Drive, Toronto",
	"206 Ee Drive, Toronto"};
	
	//initializing root for queue and stack
	NodePtr root = (NodePtr)malloc(sizeof(Node));
	strcpy(root -> address, "1 34 Aa drive, Toronto");
	root -> id = 0;
	root -> price = 300000;
	root -> nextPtr = NULL;
	
	//initializing tree 
	TreeNodePtr tree = (TreeNodePtr)malloc(sizeof(TreeNode));
	strcpy(tree -> address, "1 34 Aa Avenue, Toronto");
	tree -> id = 0;
	tree -> price = 300000;
	tree -> leftPtr = NULL;
	tree -> rightPtr = NULL;
	
	
	/*
	//testing stack operations
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
	/*
	//testing queue operations
	front = root;
	back = root;
	frontQ(front);
	backQ(front, back);
	back = enqueue(&front, back, 3, "3 56 Cc circle, Brampton", 567);
	frontQ(front);
	backQ(front, back);
	printf("\ndq");
	front = dequeue(&front);
	printf("\ndq success");
	frontQ(front);
	backQ(front,back);
	back = enqueue(&front, back, 3, "5 56 Cc circle, Brampton", 567);
	back = enqueue(&front, back, 3, "4 56 Cc circle, Brampton", 567);
	back = enqueue(&front, back, 3, "2 56 Cc circle, Brampton", 567);
	printQ(front);
	*/
	
	
	/*
	//testing tree operations
	
	insertIntoTree(&tree, 16, "2 22 Bb Boulevard, Kitchner", 444);
	insertIntoTree(&tree, 32, "3 333 Bb Boulevard, Kitchner", 444);
	insertIntoTree(&tree, 4, "2 555 Bb Boulevard, Kitchner", 444);
	insertIntoTree(&tree, 5, "2 115 Bb Boulevard, Kitchner", 444);
	insertIntoTree(&tree, 32, "2 66 Bb Boulevard, Kitchner", 444);
	
	printf("\nbinary search for id 777");
	TreeNodePtr searchTree = binarySearchById(tree, 777);
	printf("\n %d", searchTree);
	printf("\nbinary search for id 4");
	searchTree = binarySearchById(tree, 4);
	printf("\nid: %d \naddress: %s \nprice: %d",searchTree->id, searchTree->address, searchTree->price);
		
	printf("\n inorder:");
	inOrder(tree);
	
	printf("\n preorder:");
	preOrder(tree);
	
	printf("\n postorder:");
	postOrder(tree);
	*/
	//Main menu with submenus
	int mainChoice;
	do {
		printf("\n----Main Menu----"); //Main Menu
		printf("\n\n1) Stack Operations\n2) Queue Operations\n3) Tree Operations \n0) Exit");
		printf("\nEnter number as your choice: ");
		scanf("%d", &mainChoice);
		switch(mainChoice) {
			case 1:	//Stack Menu
				printf("\n");
				int stackChoice;
				printf("\nConstructing dummy stack...");
				root->nextPtr = NULL;
				for(i=0; i<6;i++){
					push(&root,i+1,dummyAddresses[i],800000);
				}
				do {
					
					printf("\n\n---Stack Operations---"); 
					printf("\n\n1) Top\n2) Push\n3) Pop\n4) Print Stack\n0) Exit Stack Operations");
					printf("\nEnter number as your choice: ");
					scanf("%d", &stackChoice);
					switch(stackChoice) {
						case 1: //Top
							top(root);
							break;

						case 2: //Push 
							printf("\nEnter id: ");
							scanf("%d", &id);
							printf("\nEnter address: ");
							scanf("%s", &address);
							printf("\nEnter price: ");
							scanf("%d", &price);
							push(&root,id, address, price);
							
							break;

						case 3: //Pop
							pop(&root);
							break;

						case 4: //Print All Data in Stack
							printf("\nPrinting Stack Listings...\n");
							printStack(root);
							break;

						case 0: //Exit Stack Menu
							printf("\n");
							break;

						default:
							printf("\nInvalid input\n\n");
					}
				} while(stackChoice != 0);
				break;

			case 2: //Queue Menu
				printf("\n");				
				int queueChoice;
				front = root;
				back = root;
				printf("\nConstructing dummy queue...");
				root->nextPtr = NULL;
				for(i=0; i<6;i++){
					back = enqueue(&front, back,i+1,dummyAddresses[i],800000);
				}
				do {
					printf("\n\n---Queue Operations---");
					printf("\n\n1) Front of Queue\n2) Back of Queue\n3) Enqueue\n4) Dequeue\n5) Print Queue\n0) Exit Queue Operations");
					printf("\nEnter number as your choice: ");
					scanf("%d", &queueChoice);
					switch(queueChoice) {
						case 1: //Front of Queue
							frontQ(front);
							break;

						case 2: //Back of Queue
							backQ(front, back);
							break;

						case 3: //Enqueue
							printf("\nEnter id: ");
							scanf("%d", &id);
							printf("\nEnter address: ");
							scanf("%s", &address);
							printf("\nEnter price: ");
							scanf("%d", &price);
							back = enqueue(&front, back, id, address, price);
							break;

						case 4: //Dequeue
							front = dequeue(&front);
							break;

						case 5: //Print All Items in Queue
							printf("\nPrinting Queue Listings...\n");
							printQ(front);
							break;

						case 0: //Exit Queue Menu
							printf("\n");
							break;

						default:
							printf("\nInvalid input\n\n");
					}
				} while(queueChoice != 0);
				break;

			case 3: //Tree Menu
				printf("\n");		
				int treeChoice;
				printf("\nConstructing dummy tree...");
				tree->leftPtr = NULL;
				tree->rightPtr = NULL;
				for(i=0; i<6;i++){
					insertIntoTree(&tree,i+1,dummyAddresses[i],800000);
				}
				do {
					printf("\n\n---Tree operations---");
					printf("\n\n1) Insert into Tree\n2) Remove by Id\n3) Binary Search with id\n4) Pre-order\n5) Post-order\n6) In-order\n0) Exit Tree Operations");
					printf("\nEnter number as your choice: ");
					scanf("%d", &treeChoice);
					switch(treeChoice) {
						case 1: //Insert into Tree
							printf("\nEnter id: ");
							scanf("%d", &id);
							printf("\nEnter address: ");
							scanf("%s", &address);
							printf("\nEnter price: ");
							scanf("%d", &price);
							insertIntoTree(&tree,id,address,price);
							break;

						case 2: //Remove from Tree

							break;

						case 3: //Search Data in Tree
							printf("\nEnter ID to search: ");
							int searchID;
							scanf("%d", &searchID);
							TreeNodePtr searchTree = binarySearchById(tree, searchID);
							if(searchTree == NULL){
								printf("\n No listing found with id: %d", searchID);
							} else {
								printf("\n Listing found: ");
								printf("\nid: %d \naddress: %s \nprice: %d",searchTree->id, searchTree->address, searchTree->price);
							}
							break;

						case 4: //preOrder
							printf("\nPrinting tree in Pre Order...");
							preOrder(tree);
							break;

						case 5: //postOrder
							printf("\nPrinting tree in Post Order...");
							postOrder(tree);
							break;

						case 6: //inOrder
							printf("\nPrinting tree in In Order...");
							inOrder(tree);
							break;

						case 0: //Exit Tree Menu
							printf("\n");
							break;

						default:
							printf("\nInvalid input\n\n");
					}
				} while(treeChoice != 0);
				break;
				
			case 4: //Exit Main Menu and Close Program
				break;
				
			default:
				printf("\nInvalid input\n\n");
		}
	} while(mainChoice != 0);
	
}


//stack operations
void push(NodePtr * stack, int id, char * address, int price){
	if(*stack == NULL){
		*stack = (NodePtr)malloc(sizeof(Node));
		(*stack) -> id = id;
		strcpy((*stack) -> address, address);
		(*stack) -> price = price;
		(*stack) -> nextPtr = NULL;
		
	} else {
		NodePtr root = (NodePtr)malloc(sizeof(Node));
		root -> id = id;
		strcpy(root -> address, address);
		root -> price = price;
		root -> nextPtr = *stack;
		(*stack) = root;
	}
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
	} else {
		printf("\n\nid: %d \naddress: %s \nprice: %d", stack->id, stack->address, stack->price);
		if(stack->nextPtr != NULL){
			printStack(stack->nextPtr);
		}
	}
}

//queue operations
void frontQ(NodePtr queue){
	if(queue == NULL){
		printf("\nNo listings found. The queue is empty.");
	} else {
		printf("\nFront house listing: \nid: %d \naddress: %s \nprice: %d", queue->id, queue->address, queue->price);
	}
}

void backQ(NodePtr queue, NodePtr back){
	if(queue == NULL){
		printf("\nNo listings found. The queue is empty.");
	} else{
		printf("\nBack house listing: \nid: %d \naddress: %s \nprice: %d", back->id, back->address, back->price);
	}
}

NodePtr enqueue(NodePtr * queue, NodePtr back, int id, char * address, int price){
	if(*queue == NULL){
		*queue = (NodePtr)malloc(sizeof(Node));
		(*queue) -> id = id;
		strcpy((*queue) -> address, address);
		(*queue) -> price = price;
		(*queue) -> nextPtr = NULL;
		back = (*queue);
		return back;
		
	}else {
		//setting up the node
		NodePtr root = (NodePtr)malloc(sizeof(Node));
		root->id = id;
		strcpy(root->address, address);
		root->price = price;
		root->nextPtr = NULL;
		
		//adding the node to the back of the queue
		back->nextPtr = root;
		return root;
	}
}

NodePtr dequeue(NodePtr * queue){
	if(*queue != NULL){
		printf("\nListing dequeued: \nid: %d \naddress: %s \nprice: %d", (*queue)->id, (*queue)->address, (*queue)->price);
		NodePtr tempPtr = *queue;
		*queue = (*queue) -> nextPtr;
		free(tempPtr);
		return (*queue);
	} else {
		printf("\nNo listing popped. The stack is empty.");
		return NULL;
	}
}

void printQ(NodePtr queue){
	if(queue == NULL){
		printf("\nNo listings to print. The queue is empty.");
	} else{
		printf("\n\nid: %d \naddress: %s \nprice: %d", queue->id, queue->address, queue->price);
		 if(queue->nextPtr != NULL){
		 	printQ(queue->nextPtr);
		 }	
	}
}

//tree operations
void insertIntoTree(TreeNodePtr * tree, int id, char * address, int price){
	if(*tree == NULL){
		*tree = (TreeNodePtr)malloc(sizeof(TreeNode));
		if(*tree != NULL){
			(*tree)->id = id;
			strcpy((*tree)->address, address);
			(*tree)->price = price;
			(*tree)->leftPtr = NULL;
			(*tree)->rightPtr = NULL;
		} else{
			printf("\nTree node with id: %d address: %s price: %d not inserted. No memory available.", id, address, price);
			
		}
	} else {
		if(id < (*tree)->id){
			insertIntoTree(&((*tree)->leftPtr), id, address, price);
		} else if(id > (*tree)->id){
			insertIntoTree(&((*tree)->rightPtr), id, address, price);
		} else {
			printf("\nListing with id %d not inserted. Id already exists. Please try again with an unique id.", id);
		}
	}
}

TreeNodePtr binarySearchById(TreeNodePtr tree, int id){
	if(tree == NULL){
		return NULL;
	} else if(tree->id == id){
		return tree;
	} else if(id < tree->id){
		binarySearchById(tree->leftPtr, id);
	} else{
		binarySearchById(tree->rightPtr, id);
	}
}
void preOrder(TreeNodePtr tree){
	if(tree != NULL){
		printf("\n\nid: %d \naddress: %s \nprice: %d", tree->id, tree->address, tree->price);
		preOrder(tree->leftPtr);
		preOrder(tree->rightPtr);
	}
}
void postOrder(TreeNodePtr tree){
	if(tree != NULL){
		postOrder(tree->leftPtr);
		postOrder(tree->rightPtr);
		printf("\n\nid: %d \naddress: %s \nprice: %d", tree->id, tree->address, tree->price);
	}
}

void inOrder(TreeNodePtr tree){
	if(tree != NULL){
		inOrder(tree->leftPtr);
		printf("\n\nid: %d \naddress: %s \nprice: %d", tree->id, tree->address, tree->price);
		inOrder(tree->rightPtr);
	}
}

