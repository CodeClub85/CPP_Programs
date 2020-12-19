#include <iostream>
using namespace std;

struct sct
{
	int data;
};
struct stk
{
	int top;
	int capacity;
	sct *array;
};
stk* create(){
	stk *s = (stk*)malloc(sizeof(stk));
	s -> top = -1;
	s -> capacity = 10;
	s -> array = (sct*)malloc(s->capacity* sizeof(sct));
	return s;
}
/*bool palinDrome(char arr[])
{
	int i = 0, l = strlen(arr);
	DynStack *S = createStack();
	while(i < l/2){
		push(S, arr[i]);
		i++;
	}
	if(l % 2 != 0)
		i++;
	while(arr[i]){
		if(arr[i] != pop(S))
			return false;
		i++;
	}
	return isEmpty(S);
}*/
class temp{
	public:
		temp(){
			cout<<"Hello, World";
		}
};

template <class T int>
T add(T n1, T n2){
	return n1+n2;
}
int main()
{
	cout<<add(4.4, 7.8);
	
	return 0;
}
