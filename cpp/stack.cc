#include<iostream>
using namespace std;
struct Array{
  int top;
  int array[10];
  Array () {
    top = 0;
  }
};
void push(Array& S,int x)
{
  S.array[S.top]=x;
  S.top++;
}
bool stack_empty(Array S)
{
  if(S.top==0) return true;
  else return false;
}
int pop(Array& S)
{
  S.top=S.top-1;
  return S.array[S.top];
}
int main()
{
  int A[]={15,6,2,9,17,3,5};
  Array B;
  for(int i=0;i<7;i++)
  {
    push(B,A[i]);
  }
  for(int i=0;i<B.top;i++) cout<<B.array[i]<<endl;
  pop(B);
  for(int i=0;i<B.top;i++) cout<<B.array[i]<<endl;

  return 0;
}





