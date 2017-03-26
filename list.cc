# include<iostream>
# include <stdlib.h>

using namespace std;
struct Node {
  int data;
  struct Node* next;
};

struct Node* allocNode (int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

struct Node* appendData (Node* parent,int data) {
  if (parent->next)
    return appendData(parent->next, data);
  else {
    parent->next = allocNode(data);
    return parent->next;
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
