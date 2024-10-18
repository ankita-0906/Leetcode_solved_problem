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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head,*kth=temp,*nextnode,*pre,*fut,*past,*p=NULL;
        while(temp!=NULL){
            //find kth node 
            int cnt=1; kth=temp;
            while(cnt<k && kth!=NULL){
            kth=kth->next;
             cnt++;
            }
            if(kth==NULL){
                if(p) p->next=temp;
                break;
            }
            nextnode=kth->next;
            kth->next=NULL;

            //reverse linked list

            pre=temp; fut=temp; past=NULL;

            while(pre!=NULL){
                fut=fut->next;
                pre->next=past;
                past=pre;
                pre=fut;
            }

            if(head==temp)
            head=kth;
            else{
              p->next=kth;
            }
            p=temp;
            temp=nextnode;

        }
        return head;
    }
};