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
    ListNode* find_middle(ListNode* head){
        ListNode*slow=head,*fast=head;
       while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       return slow;
    }
    ListNode*reverse(ListNode*right){
        if(right==NULL || right->next==NULL) return right;
        ListNode*prev=NULL,*curr=right ,*fut=right;
        while(curr){
             fut=fut->next;
            curr->next=prev;
         prev=curr; curr=fut; 
        
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // find first middle 
        if(head==NULL || head->next==NULL) return head;

        ListNode*middle=find_middle(head);
        ListNode*right=middle->next;
        middle->next=NULL;
        ListNode*head2=reverse(right);
        ListNode*temp1=head; ListNode*temp2=head2;

        while(temp1 && temp2){
            if(temp1->val !=temp2->val) return false;
            temp1=temp1->next; temp2=temp2->next;
        }
        return true;
    }
};