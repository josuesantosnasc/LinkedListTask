#include<iostream>
#include<vector>
using namespace std;


class Node {

private:

	int data;
	Node* next;

public:
	Node() {
		this->data = NULL;
		this->next = NULL;
	}

	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}

	int getData() {
		return this->data;
	}

	void setData(int data) {
		this->data = data;
	}

	Node* getNext() {
		return this->next;
	}

	void setNext(Node* next) {
		this->next = next;

		
	}
};



class LinkedList {

private:
	
	Node* beginList;
	Node* endList;
	Node* previousNode;
	
	
public:

	

	LinkedList() {
		this->beginList = NULL;
		this->endList = NULL;
		this->previousNode = NULL;
	}

	Node* getBeginList() {
		return this->beginList;
	}

	Node* getEndList() {
		return this->endList;
	}
	


	void InsertLast(int data) {
		Node* newNode = new Node();

		newNode->setData(data);

		if (this->beginList == NULL && this->endList==NULL) {
			this->beginList = this->endList =newNode;
			
		}
		else {
			this->endList->setNext(newNode);
			this->previousNode = this->endList;
			this->endList = newNode;
			
		}
		
		


	}

	void InsertFirst(int data) {
		Node* newNode = new Node();

		newNode->setData(data);
		newNode->setNext(this->beginList);

		if (this->beginList == NULL && this->endList==NULL) {
			this->beginList = this->endList = newNode;
		}
		else {
			
			this->beginList = newNode;
		}

	}

	void DeleteLast() {
		if (this->endList == NULL && this->beginList==NULL) {
			printf("\nArray empty\n");
		}
		else {

			if (this->previousNode == NULL) {
				this->endList = this->beginList = NULL;
			}
			else {

				Node* tempNode = this->endList;

				this->previousNode->setNext(NULL);
				this->endList=this->previousNode;

				free(tempNode);


			}
			

		}
	}

	void DeleteFirst() {
		

		if (this->endList == NULL && this->beginList == NULL) {
			printf("\nArray empty\n");
		}
		else {

			Node* tempNode = this->beginList;

			this->beginList = this->beginList->getNext();

			free(tempNode);

			

		


		}

	}

	void PrintList() {

		Node* beginList = this->beginList;

		while (beginList != NULL) {
			printf("%d->", beginList->getData());
			beginList = beginList->getNext();

		};

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

		list->DeleteFirst();
	}

	void printQueue() {

		list->PrintList();
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
		list->PrintList();

	}
};

int main() {

	Stack* StackList = new Stack();

	Queue* QueueList = new Queue();
	

	printf("Test for Stack :\n");
	StackList->push(10);
	StackList->push(30);
	StackList->push(40);
	StackList->push(50);

	StackList->printStack();

	printf("After removing the last element:\n");

	StackList->pop();
	StackList->printStack();

	printf("Test for Queue:\n");
	QueueList->push(10);
	QueueList->push(30);
	QueueList->push(40);
	QueueList->push(50);

	QueueList->printQueue();

	printf("After removing the first element:\n");

	QueueList->pop();
	QueueList->printQueue();






	

	


	









	
	return 0;
}