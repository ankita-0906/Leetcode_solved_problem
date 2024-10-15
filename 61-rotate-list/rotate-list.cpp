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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode*temp=head;
        int cnt=1;
        while(temp->next!=NULL){
        cnt++;
        temp=temp->next;
        }
        temp->next=head;
        ListNode*prev=NULL;
        ListNode*last=head;
        int rem=cnt-((k+cnt)%cnt);
        int i=0;
        while(i<rem){
            prev=last;
            last=last->next;
            i++;
        }
        if(prev!=NULL)
        prev->next=NULL;
        head=last;
        return head;
    }
};