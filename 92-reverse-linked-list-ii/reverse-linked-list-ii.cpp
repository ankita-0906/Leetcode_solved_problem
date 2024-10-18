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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode*low=head,*high=head,*nextnode,*past,*pre,*fut,*prev=NULL;
       int cnt=1;
       while(cnt<left){
        prev=low;
        low=low->next;
        cnt++;
       }
       cnt=1;
       while(cnt<right){
        high=high->next;
        cnt++;
       }
       
       nextnode=high->next;
       high->next=NULL;

       //reverse

       past=NULL; pre=low; fut=low;

       while(pre!=NULL){
        fut=fut->next;
        pre->next=past;
        past=pre;
        pre=fut;
       }
       low->next=nextnode;
       if(prev)
         prev->next=high;
        if(low==head){
            head=high;
        }
       return head;
    }
};