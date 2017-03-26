# include<iostream>
# include <stdlib.h>

using namespace std;
struct Node {
  int data;
  struct Node* next;
};

struct Node* allocNode (int data) {
  Node* node=(Node*)malloc(sizeof(Node));
  node->next=NULL;
  node->data=data;
  return node;
}

void appendData (Node* parent,int data) {
  if(parent->next==NULL) parent->next=allocNode(data);
  else{
    appendData(parent->next,data);
  }
}

int main() {
  Node* head = allocNode(0);
  for (int i=0; i< 10;++i)
    appendData(head, i); 

  Node* temp = head;
  while(temp->next) {
    cout << temp->next->data << endl;
    temp = temp->next;
  }
  return 0;
}
