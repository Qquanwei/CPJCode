#include<iostream>
using namespace std;
void insert_sort(int a[],int length)
{
  int key,i;
   for(int j=1;j<length;j++)
   {
     key=a[j];
     i=j-1;
     while(a[i]>a[i+1] && i>=0)
     {
       a[i+1]=a[i];
       a[i]=key;
       i=i-1;
     }
   }
}
int main()
{
  int A[]={3,2,1,9,7,8,999,0,666};
  insert_sort(A, 9);
  for(int i=0;i<9;i++)
  {
    cout << A[i]<< endl;
  }
  return 0;
}
