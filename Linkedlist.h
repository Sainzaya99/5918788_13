#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} Node;

typedef struct linkedList {
	Node* head;
	int size;
} LinkedList;

extern LinkedList* createLinkedList();
extern LinkedList* insertFirstLinkedList(LinkedList* li, int item);
extern LinkedList* insertLastLinkedList(LinkedList* li, int item);
extern LinkedList* insertAtLinkedList(LinkedList* li, int at, int item);
extern LinkedList* deleteAtLinkedList(LinkedList* li, int at);
extern void printLinkedList(LinkedList* li);
extern int sizeLinkedList(LinkedList* li);
extern void destroyLinkedList(LinkedList* li);