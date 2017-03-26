# include<iostream>
using namespace std;
void max_heapify(int a[],int i,int length)
{
  int l=2*(i+1)-1;
  int r=2*(i+1);
  int largest;
  int key;
  if(l<length && a[l]>a[i]) largest=l;
  else largest=i;
  if(r<length && a[r]>a[largest]) largest=r;
  if(largest!=i)
  {
    key=a[i];
    a[i]=a[largest];
    a[largest]=key;
    max_heapify(a,largest,length);
  }

}
void build_max_heap(int a[],int length)
{
  // 4,3,2,1,0
  for(int i=length/2 -1;i>=0;i--)  max_heapify(a,i,length);
}
void heapsort(int a[],int length)
{
  build_max_heap(a,length);
  int key;
  for(int i=length;i>1;i--)
  {
    key=a[0];
    a[0]=a[i-1];
    a[i-1]=key;
    length=length-1;
    max_heapify(a,0,length);
  }
}
int main()
{
  int A[]={4,1,3,2,16,9,10,14,8,7};
  heapsort(A,10);
  for(int i=0;i<10;i++)
  {
    cout<<A[i]<<","<<endl;
  }
  return 0;
}
