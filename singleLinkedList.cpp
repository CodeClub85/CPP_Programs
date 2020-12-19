#include <iostream>
using namespace std;

struct LinkedListNode
{
	int data;
	struct LinkedListNode *next;
};
LinkedListNode *head = NULL;
int nodeCount = 0;
int *ptr;

void insert(int,int);
void deleteNode(int);
void display();
int main()
{
	int data;
	insert(9, -1);
	insert(4, -1);
	insert(1, -1);
	insert(9, -1);
	insert(6, -1);
	deleteNode(-1);
	
	display();
	cout<<*ptr;
	
	return 0;
}

void insert(int data, int pos)
{
	LinkedListNode *new_node, *next_node, *prev_node;
	new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	if(!new_node){
		cout<<"Memory Error";
		return;
	}
	
	new_node -> data = data;
	next_node = head;
	if(pos == 1 || next_node == NULL){
		new_node -> next = next_node;
		head = new_node;
		return;
	}
	else{
		if(pos == -1)
			pos = nodeCount + 1;
		
		int i = 1;
		while(next_node != NULL && i < pos){
			prev_node = next_node;
			next_node = next_node -> next;
			i++;
		}
		prev_node -> next = new_node;
		new_node -> next = next_node;
	}
	nodeCount++;
}

void deleteNode(int pos)
{
	LinkedListNode *next_node, *prev_node;
	if(head == NULL){
		cout<<"List Empty";
		return;
	}
	
	next_node = head;
	if(pos == 1){
		head = next_node -> next;
		free(next_node);
	}
	else{
		if(pos == -1)
			pos = nodeCount;
		
		int i = 1;
		while(next_node != NULL && i < pos){
			prev_node = next_node;
			next_node = next_node -> next;
			i++;
		}
		if(next_node == NULL){
			cout<<"Position does not exist";
			return;
		}
		else{
			prev_node -> next = next_node -> next;
			ptr = &next_node -> data;
			free(next_node);
		}
	}
}

void display()
{
	LinkedListNode *current = head;
	
	while(current != NULL){
		cout<<current -> data<<' ';
		current = current -> next;
	}
	return;
}
