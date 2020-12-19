#include <iostream>
using namespace std;
#include "dynstack.h"

struct AdvancedStack
{
	struct DynStack *eltStack;
	struct DynStack *minStack;
};

AdvancedStack* createAdvancedStack(){
	AdvancedStack *S = (AdvancedStack*)malloc(sizeof(AdvancedStack));
	if(!S)
		return NULL;
	
	S -> eltStack = createStack();
	S -> minStack = createStack();
	return S;
}

void push(AdvancedStack *S, int data){
	push(S -> eltStack, data);
	if(isEmpty(S -> minStack) || top(S -> minStack) >= data)
		push(S -> minStack, data);
}

int pop(AdvancedStack *S){
	int temp;
	if(isEmpty(S -> eltStack))
		return -1;
	
	temp = pop(S -> eltStack);
	if(top(S -> minStack) == temp)
		pop(S -> minStack);
	
	return temp;
}

int getMinimum(AdvancedStack *S){
	if(isEmpty(S -> minStack))
		return 0;
	else
		return top(S -> minStack);
}
	
	
int main()
{
	AdvancedStack *S = createAdvancedStack();
	push(S, 5);
	push(S, 7);
	push(S, 3);
	push(S, 8);
	push(S, 2);
	push(S, 1);
	push(S, 4);
	//displayStack(S -> minStack);	
	pop(S);
	pop(S);
	cout<<getMinimum(S);
	
	return 0;
}
