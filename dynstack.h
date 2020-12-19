#include <iostream>
using namespace std;

struct DynStack{
	int top;
	int capacity;
	int *array;
};

DynStack* createStack(){
	DynStack *Ds = (DynStack*)malloc(sizeof(DynStack));
	if(!Ds)
		return NULL;
	Ds -> top = -1;
	Ds -> capacity = 1;
	Ds -> array = (int*)malloc(Ds -> capacity * sizeof(int));
	if(!Ds -> array)
		return NULL;
	return Ds;
}

void doubleStack(DynStack *Ds){
	Ds -> capacity *= 2;
	Ds -> array = (int*)realloc(Ds -> array, Ds -> capacity * sizeof(int));
}
		
bool isEmpty(DynStack *Ds){
	return (Ds -> top == -1);
}

bool isFull(DynStack *Ds){
	return (Ds -> top == Ds -> capacity - 1);
}
		
void push(DynStack *Ds, int data){
	if(isFull(Ds))
		doubleStack(Ds);
	Ds -> array[++Ds -> top] = data;
}

int pop(DynStack *Ds){
	if(isEmpty(Ds))
		cout<<"Stack is Empty"<<endl;
	else
		return (Ds -> array[Ds -> top--]);
}

int top(DynStack *Ds){
	if(isEmpty(Ds))
		return NULL;
	return (Ds -> array[Ds -> top]);
}

void deleteStack(DynStack *Ds){
	if(Ds){
		if(Ds -> array)
			free(Ds -> array);
		free(Ds);
	}
}

void displayStack(DynStack *Ds){
	for(int i = 0; i<=Ds -> top; i++){
		cout<<Ds -> array[i]<<endl;
	}
}
