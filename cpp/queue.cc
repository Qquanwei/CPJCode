#include<iostream>
using namespace std;
struct Array{
  int data[10];
  int tail;
  int head;
  int length;
  Array () {
    tail=0;
    head=0;
    length=10;
  }
};
void Enqueue(Array& S,int x)
{
  S.data[S.tail]=x;
  if(S.tail==S.length-1) S.tail=0;
  else S.tail=S.tail+1;
}
int Dequeue(Array& S)
{
  int x=S.data[S.head];
  if(S.head==S.length-1) S.head=0;
  else S.head=S.head+1;
  return x;
}
int main()
{
  int A[]={12,3,6,5,9,43,7};
  Array queue;
  for(int i=0;i<7;i++)
  {
    Enqueue(queue,A[i]);
  }
  for(int j=queue.head;j<queue.tail;j++)
  {
    cout<<queue.data[j]<<endl;
  }
  int y=Dequeue(queue);
  cout<<y<<endl;
  return 0;
}
