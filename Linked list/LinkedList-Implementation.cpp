#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(int x){
      this->data=x;
  }
};
//Insert At Beginning
void insertAtbeg(Node* &head,int x){
 Node* temp=new Node(x);
 temp->next=head;
 head=temp;
}
//Insert At End
void insertAtend(Node* &head,int x){
  Node* temp=new Node(x);
  temp->next=NULL;
  if(head==NULL){
    head=temp;
  }
  else{
      Node* p=head;
      while(p->next!=NULL){
          p=p->next;
      }
      p->next=temp;
      
  }
}
//Deleting Node starting with 0
void deleteNode(Node* &head, int position)
{
    if (head == NULL)
        return;
 
    Node* temp =head;
 
    // If head needs to be removed
    if (position == 0) {
        head = temp->next;

        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++){
        temp = temp->next;
    }
    Node* next = temp->next->next;
    free(temp->next); 
    temp->next = next;
}
//Print the Linked List
void printLL(Node* head){
         Node* temp=head;
         while(temp!=NULL){
             cout<<temp->data<<" ";
             temp=temp->next;
         }cout<<endl;
}
int main(){
    Node* head=NULL;
    insertAtbeg(head,2);
    insertAtbeg(head,1);
    insertAtend(head,3);
    insertAtend(head,4);
    insertAtend(head,5);
    deleteNode(head,1);
    printLL(head);

    return 0;
}
