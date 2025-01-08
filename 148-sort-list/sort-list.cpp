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
    ListNode* merge(ListNode*left,ListNode*right){
        ListNode*head3=new ListNode(); ListNode*temp=head3;
        while(left && right){
           
            if(left->val<right->val){
                if(head3==NULL){
                    head3=temp=left;
                }
               temp->next=left; temp=left;
              left=left->next;
            }
            else{
                if(head3==NULL){
                    head3=temp=right;
                }
               temp->next=right; temp=right;
                right=right->next;
            }
        }
        while(left){
             temp->next=left; temp=left;
              left=left->next;
        }
        while(right){
            temp->next=right; temp=right;
              right=right->next;
        }
        return head3->next;
    }
    ListNode*sort(ListNode*head1){
        if(head1==NULL|| head1->next==NULL) return head1;
        ListNode*mid=middle(head1); ListNode*righthand=mid->next;
        mid->next=NULL;
        ListNode*left=sort(head1);
        ListNode*right=sort(righthand);
        return merge(left,right);
    }

    ListNode*middle(ListNode* head2){
        ListNode*slow=head2,*fast=head2;

        while(fast->next && fast->next->next){
            slow=slow->next; fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        return sort(head);
    }
};