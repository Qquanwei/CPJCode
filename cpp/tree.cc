# include<iostream>
# include <stdlib.h>

using namespace std;
struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* allocnode(int data)
{
  Node* node=(Node*)malloc(sizeof(Node));
  node->data=data;
  node->left=NULL;
  node->right=NULL;
    return node;
}
void insert_node(Node* parent,int data)
{
  if(parent->data<=data)
  {
    if(parent->left==NULL) parent->left=allocnode(data);
    else{
      insert_node(parent->left,data);
    }
  }
  else{
    if(parent->right==NULL) parent->right=allocnode(data);
    else{
      insert_node(parent->right,data);
    }
  }
}

void visitTree(Node* parent)
{
  if(parent->left)  visitTree(parent->left);
    cout<<parent->data<<endl;
  if(parent->right) visitTree(parent->right);
}

int main() {
  int a[] = {10,3,2,8,5,1,0};
  Node* head = allocnode(5);
  for ( int i=0;i<7;++i)
    insert_node(head,a[i]);
  visitTree(head);
  return 0;
}
