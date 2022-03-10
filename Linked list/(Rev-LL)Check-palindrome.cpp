// Checking Palindrome (By reversing half of the Linked-List)
/*

    class Node {
        public :
        int data;
        Node *next;
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };
*/
//Reversing LL code
// 
void reverse(Node* &head)
{
     Node* prev = NULL;
     Node* current =head;
     Node* next;
     
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head=prev;
}

bool isPalindrome(Node* head){
     if(head==NULL || head->next==NULL)
      return true;
//Finding Mid
    Node* fast=head;
    Node* slow=head;
    Node* mid=NULL;
    Node* prev_slow=NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev_slow=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev_slow->next=NULL;
    // For reversing linkedlist -- we get even and odd's .So we need to check that
     
    //fast would become NULL when there are even in linked-list and Not NULL for odd 
    if(fast==NULL)
     mid=slow;
    else
     mid=slow->next;
    
     Node* first_half=head;
     reverse(mid);
      
//Check
     while(mid!=NULL){
         if(first_half->data!=mid->data)
          return false;
          first_half=first_half->next;
          mid=mid->next;
     }
     return true;
}



