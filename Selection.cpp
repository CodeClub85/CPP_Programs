
#include<iostream>
using namespace std;

void pri(int a[],int n)
{
	int h;
	for(h=0;h<n;h++)
	{
		cout<<a[h]<<"\t";
	}
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main()
{
	int i,j, jMin;
	int aLength;
	int a[]={24,11,54,44,67,65};
	aLength=sizeof(a)/sizeof(a[0]);
	for (i = 0; i < aLength-1; i++)
	{
	    for (j = i+1; j < aLength; j++)
	    {   
	      jMin = i;
	      if (a[j] < a[jMin])
	        	jMin = j;
	      if(jMin != i) 
	    		swap(&a[i], &a[jMin]);
	    }

	}
	pri(a,aLength);
	
	
	
	return 0;
}
