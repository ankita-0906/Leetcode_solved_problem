/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head==NULL || head->next==NULL) return true;
        ListNode*slow=head,*fast=head->next;

        //finding the middle 1
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; fast=fast->next->next;
        }

       ListNode*head2=slow->next;
       slow->next=NULL;
       ListNode*pre2=head2,*fut2=head2,*prev2=NULL;
      
     //reverse a linked list
    while(pre2){
      fut2=fut2->next;
      pre2->next=prev2; prev2=pre2;pre2=fut2;
      }
      head2=prev2;
       ListNode*temp1=head,*temp2=head2;
      while(temp1 && temp2){
        if(temp1->val!=temp2->val) return false;
        temp1=temp1->next;
        temp2=temp2->next;
      }
      return true;

    }
};