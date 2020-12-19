#include <iostream>
using namespace std;

struct StackNode{
	int data;
	StackNode *down;
};
struct StackNode * create(){
	return NULL;
}

void push(int data, StackNode **top){
	StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
	if(!newNode)
		return;
	newNode -> data = data;
	newNode -> down = *top;
	*top = newNode;
}

int pop(StackNode **top){
	if(top == NULL){
		cout<<"Stack is empty";
		return 0;
	}
	StackNode *temp = *top;
	int data;
	data = temp -> data;
	*top = temp -> down;
	free(temp);
	return data;
}

int main(){
	
	StackNode *top = create();
	for(int i = 1; i<10; i++){
		push(i, &top);
	}
	
	cout<<pop(&top);
	StackNode *current = top;
	while(current != NULL){
		cout<<current -> data<<endl;
		current = current -> down;
	}
	return 0;
}
