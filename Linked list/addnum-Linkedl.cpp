/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */-------------------------------------------------------------------------

  /* Example: Adding from first
        Input: l1 = [2,4,3], l2 = [5,6,4]
        Output: [7,0,8]
        Explanation: 342 + 465 = 807.    */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();    //Dummy linked-list
        ListNode *temp = dummy;
        int carry = 0;
        while (l1 != NULL ||  l2 != NULL || carry)
        {
            int sum = 0;
            sum+=carry;
            
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1 -> next;
            }
            
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2 -> next;
            }
            ListNode* t=new ListNode(sum%10);
            temp->next=t;
            temp=temp->next;
            carry=sum/10;
        }
        //Starting from dummy->next. Since, it is a dummy linkedlist(Convinient to make linked list)
        return dummy->next; 
    }
};