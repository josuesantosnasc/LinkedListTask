#include<iostream>
#include<vector>
using namespace std;



class LinkedList {

	
	
public:

	int data;
	LinkedList* next;
	LinkedList* top;
	LinkedList* front;

	LinkedList() {
		this->top = NULL;
		this->front = NULL;
	}

	void printList() {
		LinkedList* ptr = this->top;

		

		while (ptr != NULL) {

			printf("%d->", ptr->data);
			ptr = ptr->next;
		}

		printf("NULL\n");
	

	}

	

	void InsertLast(int data) {
		LinkedList* link = new LinkedList();

		
		link->data = data;

		link->next =this->top;

		this->top = link;


	}

	void DeleteLast() {
		if (this->top == NULL) {
			printf("\nArray empty\n");
		}
		else {
			LinkedList* temp = this->top;

			this->top = this->top->next;
			free(temp);

		}
	}

	void PrintFromEnd() {

		printf("The stack:\n");
		LinkedList* temp = this->top;

		while (temp != NULL) {
			printf("%d->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");

	}


	void InsertFirst(int newElement) {

		LinkedList* newNode = new LinkedList();

		newNode->data = newElement;
		newNode->next = NULL;

		if (this->front == NULL && this->top == NULL) {
			this->front = this->top = newNode;
		}
		else {
			this->top->next = newNode;
			this->top = newNode;
		}

	}
	

	 void DeleteFirstNode() {
		 LinkedList* temp;
		 if (this->front == NULL) {
			 printf("Queue is empty");
		 }
		 else {
			 temp = this->front;

			 this->front = front->next;

			 if (front == NULL) {
				 top = NULL;
			 }

			 free(temp);
		 }

	
	}

	 void PrintFromFirst() {
		 LinkedList* temp = this->front;
		 while (temp) {
			 printf("%d->", temp->data);
			 temp = temp->next;
		 }
		 printf("NULL\n");
	 }
};


class Queue{
public:
	
	LinkedList* list;


	Queue() {
		list = new LinkedList();
		
	}

	


	void push(int newElement) {
		list->InsertFirst(newElement);
	}


	void pop() {

		list->DeleteFirstNode();
	}

	void printQueue() {

		list->PrintFromFirst();
	}
};

class Stack{
public:

	LinkedList* list;

	

	Stack() {
		
		list = new LinkedList();
	}



	void push(int newElement) {
		list->InsertLast(newElement);


	}

	void pop() {
		list->DeleteLast();
	}

	void printStack() {
		list->PrintFromEnd();

	}
};

int main() {

	Stack* StackList = new Stack();
	Queue* QueueList = new Queue();

	printf("Test for Stack List:\n");
	StackList->push(10);
	StackList->push(20);
	StackList->push(50);
	StackList->push(80);

	StackList->printStack();

	StackList->pop();
	printf("After removing the element:\n");
	StackList->printStack();

	printf("Test for Queue List:\n");
	QueueList->push(16);
	QueueList->push(45);
	QueueList->push(78);
	QueueList->push(34);

	QueueList->printQueue();

	QueueList->pop();
	printf("After removing the element:\n");
	QueueList->printQueue();









	
	return 0;
}