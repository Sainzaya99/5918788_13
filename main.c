#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LinkedList.h"

int main() {
	LinkedList* li = createLinkedList();

	int menu; 
	int value;
	int index;

	do {
		printf("\n===== Linked List Menu =====\n");
		printf("1. Add at first\n");
		printf("2. Add at last\n");
		printf("3. Add at index\n");
		printf("4. Delete at index\n");
		printf("5. Print list\n");
		printf("6. Check list size\n");
		printf("0. Exit\n");
		printf("Select menu: ");

		scanf("%d", &menu);

		if (menu == 1) {
			printf("Enter integer: ");
			scanf("%d", &value);
			li = insertFirstLinkedList(li, value);
		}
        else if (menu == 2) {
			printf("Enter integer: ");
			scanf("%d", &value);
			li = insertLastLinkedList(li, value);
		}
        else if (menu == 3) {
			printf("Enter index: ");
			scanf("%d", &index);
			printf("Enter integer: ");
			scanf("%d", &value);
			li = insertAtLinkedList(li, index, value);
		}
        else if (menu == 4) {
			printf("Enter index: ");
			scanf("%d", &index);
			li = deleteAtLinkedList(li, index);
		}
        else if (menu == 5) {
			printLinkedList(li);
		}
		else if (menu == 6) {
			printf("List size: %d\n", sizeLinkedList(li));
		}
		else if (menu == 0) {
			destroyLinkedList(li);
			printf("Program ended.\n");
		}
		else {
			printf("Invalid menu.\n");
		}
	} while (menu != 0);

	return 0;
}