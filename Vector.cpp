#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printVector(char *s, vector<T> &v){
	cout<<s<<" = (";
	if(v.size() == 0){
		cout<<")\n";
		return;
	}
	typename vector<T>::const_iterator j =  v.begin();
	for(; j<v.end()-1; j++)
		cout<<*j<<' ';
	cout<<*j<<")\n";
}

int main(){
	
	int arr[] = {1, 2, 3, 4, 5};
	vector<int> v1;
	for(int i = 0; i<5; i++)
		v1.push_back(arr[i]);
	
	vector<int> v2(5,7);
	vector<int>::iterator i1 = v1.begin()+1;
	vector<int> v3(i1, i1+2);
	vector<int> v4(6);
	v4.clear();
	v4.insert(v4.begin(), v3[1]);
	v4.insert(v4.begin(), v3[1]);
	v4.insert(v4.end()-1, 2, 4);
	
	printVector("vn", v4);
	
	return 0;
}
