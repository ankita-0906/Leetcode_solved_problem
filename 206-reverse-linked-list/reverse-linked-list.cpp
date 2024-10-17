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
    ListNode* reverseList(ListNode* head) {
       
        if(head==NULL) return head;
        if(head->next==NULL) return head;
         ListNode*prev=NULL;
        ListNode*pr=head;
        ListNode*fut=head;
        while(pr!=NULL){
            fut=fut->next;
            pr->next=prev;
            prev=pr;
            pr=fut;
        }
        return prev;
    }
};