#include <iostream>
using namespace std;
struct DLLNode
{
	DLLNode *prev;
	int data;
	DLLNode *next;
};
DLLNode *head = NULL;
DLLNode *tail = NULL;
int nodeCount = 0;

void insertInDLL(int, int);
void display();
int main()
{
	for(int i = 1; i < 10; i++)
		insertInDLL(i, 1);
	display();
	return 0;
}

void insertInDLL(int data, int pos)
{
	DLLNode *newNode, *nextNode;
	newNode = (DLLNode*)malloc(sizeof(DLLNode));
	if(!newNode){
		cout<<"Memory Error";
		return;
	}
	newNode -> data = data;
	if(pos == 1 || head == NULL){
		newNode -> next = head;
		newNode -> prev = NULL;
		if(head)
			head -> prev = newNode;
		head = newNode;
	}
	else{
		if(pos == -1)
			pos = nodeCount + 1;
		while(nextNode -> next != NULL){
			nextNode = nextNode -> next;
		}
	}
	if(tail == NULL)
		tail = newNode;
}

void display()
{
	DLLNode *current = tail;
	while(current != NULL)
	{
		cout<<current -> data<<endl;
		current = current -> prev;
	}
}
