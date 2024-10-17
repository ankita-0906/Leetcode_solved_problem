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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode*head1=head,*head2=head->next,*temp1=head,*temp2=head2,*odd=head1,*even=head2;
        while(even!=NULL && even->next!=NULL){
           odd=odd->next->next;
           even=even->next->next;
           temp1->next=odd;
           temp2->next=even;
           temp1=odd; temp2=even;
        }
        odd->next=head2;
        return head1;
    }
};