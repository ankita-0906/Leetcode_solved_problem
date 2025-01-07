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
        ListNode*slow=head,*fast=head;

        //finding the middle 1
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next; fast=fast->next->next;
        }

        // reverse the LL from next to middle 1 to end

        ListNode*prev=NULL,*pre=slow->next,*fut=slow->next;
        while(pre){
            fut=fut->next;
            pre->next=prev; prev=pre; pre=fut;
        }
        slow=head;
        while(prev){
            if(slow->val!=prev->val) return false;
            slow=slow->next;prev=prev->next;
        }
        return true;
    }
};