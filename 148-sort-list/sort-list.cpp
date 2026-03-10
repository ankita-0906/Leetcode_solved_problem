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
   ListNode* find_middle( ListNode*head){
     ListNode*slow=head, *fast=head;
     while(fast->next!=NULL  &&  fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
     }
     return slow;
   }
  ListNode*  merge(ListNode* head,ListNode* left, ListNode* right){
    ListNode* dummy = new ListNode(-1);
ListNode* temp = dummy;
       ListNode* temp1=left, * temp2=right;
       while(temp1!=NULL && temp2!=NULL){
        if(temp1->val<temp2->val){
            temp->next=temp1; temp=temp1; temp1=temp1->next;
        }
        else {
            temp->next=temp2; temp=temp2; temp2=temp2->next;
        }
      
       }
       while(temp1!=NULL){
        temp->next=temp1; temp=temp1; temp1=temp1->next;
       }

       while(temp2!=NULL){
        temp->next=temp2; temp=temp2; temp2=temp2->next;
       }

       head=dummy->next;
       return head;
   }
   ListNode* rec(ListNode* head){
    if(head->next ==NULL) return head;
    ListNode*middle =find_middle(head);
   ListNode* right = middle->next;
    middle->next = NULL;

ListNode* left = rec(head);
right = rec(right);
   
     return merge(head,left,right);
   }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        return rec(head);
        
    }
};