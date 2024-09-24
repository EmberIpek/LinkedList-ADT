#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node_t;

typedef struct LinkedList {
	Node_t *head;
	Node_t *tail;
}LinkedList_t;

//PASS
Node_t* CreateAndInitNode(int value) {
	/*
	• Allocate memory on the heap for the node.
	• Initalize the date field of the node to the value passed to the function.
	• Return the address of the node.
	*/
	Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));
	newNode->data = value;
	newNode->next = NULL;
	
	return newNode;
}

Node_t* FindValue(LinkedList_t *list, int value) {
	/*
	• Return the address of the node containing the specified data value.
		◦ If more than one node contains the specified value, return the address of the first instance.
	• If the data value is not found in the list
		◦ Return NULL.
		◦ Print the message “Value not found.”
	*/
	Node_t *currentNode = list->head;
	
	while(currentNode != NULL) {
		if(currentNode->data == value) {
			return currentNode;
		}
	}
	printf("Value not found.\n");
	
	return NULL;
}

Node_t* FindIndex(LinkedList_t *list, int index) {
	/*
	• Return the address of the node at the specified index.
	• If the index is invalid (i.e. less than 0)
		◦ Return NULL.
		◦ Print the message “Invalid index.”
	• If the index is not found in the list
		◦ Return NULL.
		◦ Print the message “Index not found.”
	*/
	Node_t *currentNode = list->head;
	
	if(index < 0) {
		printf("Invalid index.\n");
		
		return NULL;
	}
	for(int i = 0; i <= index; i++) {
		currentNode = currentNode->next;
		if(currentNode->next == NULL && i < index) {
			printf("Index not found.\n");
			
			return NULL;
		}
	}
	
	return currentNode;
}

void InsertAfter(LinkedList_t *list, Node_t *newNode, Node_t *currNode) {
	/*
	• Insert the new node into the list after the current node.
		◦ If the current node is NULL, insert the new node at the beginning of the list.
	*/
	if(currNode == NULL) {
		if(list->head == NULL) {
			list->head = newNode;
			list->tail = newNode;
		}
		/*
		else if(list->head->next == NULL) {
			list->head = newNode;
			newNode->next = list->tail;
		}
		*/
		else {
			newNode->next = list->head;
			list->head = newNode;
		}
	}
	
	else if(currNode == list->tail) {
		currNode->next = newNode;
		newNode->next = NULL;
		list->tail = newNode;
	}
	
	else {
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	
	return;
}

//PASS
int InsertAfterValue(LinkedList_t *list, Node_t *newNode, int value) {
	/*
	• Insert the new node into the list after the node containing the specified data value.
		◦ If more than one node contains the specified data value, insert after the first instance.
	• Return 0 if the node is successfully inserted into the list.
	• If the node is not inserted into the list
		◦ Return -1.
		◦ Print the message “Node not inserted.”
	*/
	Node_t* currentNode = list->head;
	
	while(currentNode != NULL) {
		if(currentNode->data == value) {
			InsertAfter(list, newNode, currentNode);
			
			return 0;
		}
		currentNode = currentNode->next;
	}
	printf("Value not found.\n");
	printf("Node not inserted.\n");
	
	return -1;
}

//PASS
int InsertAfterIndex(LinkedList_t *list, Node_t *newNode, int index) {
	/*
	• Insert the new node into the list after the node at the specified index.
	• Return 0 if the node is successfully inserted into the list.
	• If the node is not inserted into the list
		◦ Return -1.
		◦ Print the message “Node not inserted.”
	• If the specified index is invalid (i.e. less than 0)
		◦ Return -1.
		◦ Print the message “Invalid index.”
	*/
	Node_t* currentNode = list->head;
	int i = 0;
	
	if(index < 0) {
		printf("Invalid index.\n");
		printf("Node not inserted.\n");
		
		return -1;
	}
	/*
	if(index == 0) {
		InsertAfter(list, newNode, NULL);
	}
	*/
	while(currentNode != NULL) {
		if(i == index) {
			InsertAfter(list, newNode, currentNode);
			return 0;
		}
		i++;
		currentNode = currentNode->next;
	}
	printf("Index not found.\n");
	printf("Node not inserted.\n");
	
	return -1;
}

void Remove(LinkedList_t *list, Node_t *remNode) {
	/*
	• Remove the specified node from the list.
	*/
	if(list->head == remNode) {
		list->head = remNode->next;
		free(remNode);
	}
	else if(list->tail == remNode) {
		Node_t *currentNode = list->head;
		
		while(currentNode->next != remNode) {
			currentNode = currentNode->next;
		}
		list->tail = currentNode;
		list->tail->next = NULL;
		free(remNode);
	}
	else {
		Node_t *currentNode = list->head;
		
		while(currentNode->next != remNode) {
			currentNode = currentNode->next;
		}
		currentNode->next = remNode->next;
		free(remNode);
	}
	
	return;
}

int RemoveByValue(LinkedList_t *list, int value) {
	/*• Remove the node containing the specified data value from the list.
		◦ If more than one node contains the specified data value, remove the first instance.
	• Return 0 if the node is successfully removed from the list.
	• If the node is not removed from the list
		◦ Return -1.
		◦ Print the message “Node not removed.”
	*/
	Node_t *currentNode = list->head;
	
	while(currentNode != NULL) {
		if(currentNode->data == value) {
			Remove(list, currentNode);
			
			return 0;
		}
		currentNode = currentNode->next;
	}
	printf("Value not found.\n");
	printf("Node not removed.\n");
	
	return -1;
}

int RemoveByIndex(LinkedList_t *list, int index) {
	/*
	• Remove the node at the specified index from the list.
	• Return 0 if the node is successfully removed from the list.
	• If the node is not removed from the list
		◦ Return -1.
		◦ Print the message “Node not removed.”
	• If the specified index is invalid (i.e. less than 0)
		◦ Return -1.
		◦ Print the message “Invalid index.
	*/
	Node_t *currentNode = list->head;
	int i = 0;
	
	if(index < 0) {
		printf("Invalid index.\n");
		printf("Node not removed.\n");
		
		return -1;
	}
	while(currentNode != NULL) {
		if(i == index) {
			Remove(list, currentNode);
			
			return 0;
		}
		i++;
		currentNode = currentNode->next;
	}
	printf("Index not found.\n");
	printf("Node not removed.\n");
	
	return -1;
}

//PASS
LinkedList_t* ReverseList(LinkedList_t *list) {
	/*
	• Create a copy of the list in reverse order.
	• Return a pointer to the new list.
	*/
	LinkedList_t *reversedList = (LinkedList_t*)malloc(sizeof(LinkedList_t));
	reversedList->head = NULL;
	reversedList->tail = NULL;
	Node_t *currentNode = list->head;
	
	
	while(currentNode != NULL) {
		Node_t *newNode = CreateAndInitNode(currentNode->data);
		InsertAfter(reversedList, newNode, NULL);
		currentNode = currentNode->next;
	}
	
	/*
	int length = 0;
	
	while(currentNode->next != NULL) {
		currentNode = currentNode->next;
		length++;
	}
	for(int i = 0; i <= length; i++) {
		currentNode = list->head;
		for(int j = 0; j < length - i; j++) {
			currentNode = currentNode->next;
		}
		Node_t *newNode = CreateAndInitNode(currentNode->data);
		if(i == 0) {
			InsertAfter(reversedList, newNode, NULL);
		}
		else {
			InsertAfterIndex(reversedList, newNode, i - 1);
		}
	}
	*/
	
	
	return reversedList;
}

int IsPalindrome(LinkedList_t *list) {
	/*
	• Determine if the list is a palindrome.
	• Return 1 if the list is a palindrome; otherwise, return 0.
	*/
	LinkedList_t *reversedList = ReverseList(list);
	Node_t *currentNode = list->head;
	Node_t *currentNodeReverse = reversedList->head;
	
	while(currentNode != NULL) {
		if(currentNode->data != currentNodeReverse->data) {
			return 0;
		}
		currentNode = currentNode->next;
		currentNodeReverse = currentNodeReverse->next;
	}
	
	return 1;
}

//PASS
void PrintList(LinkedList_t *list) {
	/*
	• Print the data value of each node in the list, starting with the head node.
	*/
	Node_t *currentNode = list->head;
	
	while(currentNode != NULL) {
		printf("%d\n", currentNode->data);
		currentNode = currentNode->next;
	}
	
	return;
}

int main() {
	
	return 0;
}