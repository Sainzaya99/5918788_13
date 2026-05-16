#include "Linkedlist.h"

LinkedList* createLinkedList() {
	LinkedList* li = (LinkedList*)malloc(sizeof(LinkedList));

	li->head = NULL;
	li->size = 0;

	return li;
}

LinkedList* insertFirstLinkedList(LinkedList* li, int item) {
	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr-> data= item;
    ptr->next = li->head;

	li->head = ptr;
	li->size++;

	return li;
}
LinkedList* insertLastLinkedList(LinkedList* li, int item) {
	Node* nptr = (Node*)malloc(sizeof(Node));
	nptr->data = item;
	nptr->next = NULL;
    
	if (li->head == NULL) {
		li->head = nptr;
	} 
	else {
		Node* ptr = li->head;

		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = nptr;
	}

	li->size++;

	return li;
}
LinkedList* insertAtLinkedList(LinkedList* li, int at, int item) {
	if (at < 0 || at > li->size) {
		return li;
	}

	if (at == 0) {
		return insertFirstLinkedList(li, item);
	}

	Node* nptr = (Node*)malloc(sizeof(Node));
	nptr->data = item;
	nptr->next = NULL;

	Node* fptr = li->head;

	for (int i = 0; i < at - 1;i++) {
		fptr = fptr->next;
	}

	nptr->next = fptr->next;
	fptr->next = nptr;

	li->size++;

	return li;
}
LinkedList* deleteAtLinkedList(LinkedList* li, int at) {
	if (at < 0 || at >= li->size) {
		printf("Invalid index.\n");
		return li;
	}

	if (at == 0) {
		Node* fptr = li->head;
		li->head = fptr->next;

		printf("Deleted value: %d\n", fptr->data);
		free(fptr);
	}
	else {
		Node* nptr = li->head;

		for (int i = 0; i < at - 1; i++) {
			nptr = nptr->next;
		}

		Node* fptr = nptr->next;
		nptr->next = fptr->next;

		printf("Deleted value: %d\n", fptr->data);
		free(fptr);
	}
	
	li->size--;

	return li;
}
void printLinkedList(LinkedList* li) {
	Node* nptr = li->head;
	
	printf("List: ");

	while (nptr != NULL) {
		printf("%d ", nptr->data);
		nptr = nptr->next;
	}
	printf("\n");
}
int sizeLinkedList(LinkedList* li) {
	return li->size;
}
void destroyLinkedList(LinkedList* li) {
	Node* nptr, * mptr;
	for (nptr = li->head; nptr != NULL; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}

	free(li);
}
