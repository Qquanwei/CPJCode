#include<iostream>
#include<stdlib.h>
using namespace std;

void merge(int a[], int p,int q, int r) {
  int n1=q-p+1;
  int n2=r-q;
  int* L=(int*)malloc(sizeof(int) * n1);
  int* R=(int*)malloc(sizeof(int) * n2);
  for(int i=0; i<n1;i++) L[i] =a[p+i];
  for(int i=0;i<n2; i++) R[i] =a[q+1+i];
  int k=p;
  int i=0;
  int j=0;
  while(k<=r){
    if((L[i] <=R[j] || (j>=n2)) && i<n1){
      a[k] =L[i];
      i++;
    }
    else if((L[i] >R[j] || (i>=n1)) && j<n2){
      a[k] =R[j];
      j++;
    }
    k++;
  }
}

void merge_sort(int a[],int p,int r){
  if(p>=r) return;
  int q=(p+r) /2;
  merge_sort(a,p,q);
  merge_sort(a,q+1,r);
  merge(a,p,q,r);
}
int main()
{
  int a[] = {3,2,5,1,7};
  merge_sort(a, 0 , 4);
  for(int i=0;i<5;i++)
  {
    cout << a[i] <<endl;
  }
  return 0;
}
