#include <iostream>
using namespace std;

bool balancingExpr(char expr[]){
	char stack[10], topElt;
	int top = -1;
	for(int i = 0; expr[i] != '\0'; i++){
		if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
			stack[++top] = expr[i];
			
		else if(expr[i] == ')' || expr[i] == ']' || expr[i] == '}'){
			if(top == -1)
				return false;
			topElt = stack[top--];
			switch(expr[i]){
				case ')':
					if(topElt == '[' || topElt == '{')
						return false;
					break;
				case ']':
					if(topElt == '(' || topElt == '{')
						return false;
					break;
				case '}':
					if(topElt == '[' || topElt == '(')
						return false;
					break;
			}
		}
		else
			continue;
	}
	if(top == -1)
		return true;
	else
		return false;
}

int main()
{
	if(balancingExpr("[a+h])"))
		cout<<"Hello, World";
	
	return 0;
}
