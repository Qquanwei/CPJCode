#include<iostream>
using namespace std;

int Partition(int a[],int p,int r)
{
	int x=a[r-1];
	int i=p-2;
	int key=0;
	int key1=0;
	for(int j=p-1;j<r-1;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			key=a[i];
			a[i]=a[j];
			a[j]=key;
		}
	}
	key1=a[i+1];
	a[i+1]=a[r-1];
	a[r-1]=key1;
	return i+1;

}
void quick_Sort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=Partition(a,p,r);
		quick_Sort(a,p,q-1);
		quick_Sort(a,q+1,r);
	}
}
int main()
{
	int A[]={2,8,7,1,3,5,6,4};
	quick_Sort(A,1,8);
	for(int i=0;i<8;i++)
	{
		cout<<A[i]<<endl;
	}
	return 0;
}
