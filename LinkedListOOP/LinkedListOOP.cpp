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
	Node* nextToLastNode;
	
	
public:

	

	LinkedList() {
		this->beginList = NULL;
		this->endList = NULL;
		this->nextToLastNode = NULL;
	}

	LinkedList(Node* beginList,Node* endList) {
		this->beginList = beginList;
		this->endList = endList;
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
			this->nextToLastNode = this->endList;
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

			if (this->nextToLastNode == NULL) {
				this->nextToLastNode = this->beginList;
			}
		}

	}

	void DeleteLast() {
		if (this->endList == NULL && this->beginList==NULL) {
			printf("\nArray empty\n");
		}
		else {

			if (this->nextToLastNode == NULL) {
				this->endList = this->beginList = NULL;
			}
			else {

				Node* tempNode = this->endList;

				this->nextToLastNode->setNext(NULL);
				this->endList=this->nextToLastNode;

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

	void DeleteSpecificValue(int value) {
		Node* tempBeginList = this->beginList;
		Node* RemovingNode;

		
		if (tempBeginList != NULL && tempBeginList->getData() == value) {
			RemovingNode = this->beginList;
			this->beginList = RemovingNode->getNext();
			free(RemovingNode);
		}
		else {
			while (tempBeginList != NULL && tempBeginList->getNext()->getData() != value && tempBeginList->getNext() != NULL) {

				tempBeginList = tempBeginList->getNext();

			}

			if (tempBeginList != NULL && tempBeginList->getNext() != NULL) {
				RemovingNode = tempBeginList->getNext();
				tempBeginList->setNext(RemovingNode->getNext());
				
				free(RemovingNode);
			}
			else if (tempBeginList!=NULL && (tempBeginList->getNext()->getData()==this->endList->getData())) {
				RemovingNode = tempBeginList->getNext();
				tempBeginList->setNext(NULL);
				this->endList = tempBeginList;

				free(RemovingNode);
			}
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
private:
	LinkedList* list;


public:
	
	


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
private:
	LinkedList* list;

public:



	

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



	LinkedList* LinkedListGeneral = new LinkedList();

	printf("Test for Linked List :\n");

	LinkedListGeneral->InsertLast(45);
	LinkedListGeneral->InsertLast(35);
	LinkedListGeneral->InsertLast(67);

	printf("Initial Linked List:\n");

	LinkedListGeneral->PrintList();


	printf("Inserting elements into the beginning of Linked List:\n");
	printf("First element:50\n");
	LinkedListGeneral->InsertFirst(50);
	LinkedListGeneral->PrintList();
	
	printf("Second element:30\n");
	LinkedListGeneral->InsertFirst(30);
	LinkedListGeneral->PrintList();

	

	printf("Inserting elements into the end of Linked List:\n");
	printf("First element:90\n");
	LinkedListGeneral->InsertLast(90);
	LinkedListGeneral->PrintList();

	printf("Second element:10\n");
	LinkedListGeneral->InsertLast(10);
	LinkedListGeneral->PrintList();

	printf("Removing elements from the beginning of Linked List:\n");
	printf("First element:30\n");
	LinkedListGeneral->DeleteFirst();
	LinkedListGeneral->PrintList();

	printf("Second element:50\n");
	LinkedListGeneral->DeleteFirst();
	LinkedListGeneral->PrintList();

	printf("Removing elements from the end of Linked List:\n");
	printf("First element:10\n");
	LinkedListGeneral->DeleteLast();
	LinkedListGeneral->PrintList();



	printf("Removing 35:\n");
	LinkedListGeneral->DeleteSpecificValue(35);
	LinkedListGeneral->PrintList();

	printf("\n\n");
	






	

	


	









	
	return 0;
}