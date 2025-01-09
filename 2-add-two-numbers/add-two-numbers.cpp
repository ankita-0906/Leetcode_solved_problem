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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=l1,*temp2=l2;int carry=0;
        ListNode*dummy=new ListNode(-1);ListNode*temp=dummy;
        while(temp1 || temp2 || carry){
            int value=0;
            if(temp1){
                value=temp1->val; temp1=temp1->next;
            }
            if(temp2){
                value=temp2->val+value; temp2=temp2->next;
            }
            value=value+carry;
            
                carry=value/10;
                value=value%10;
                ListNode*newnode=new ListNode(value);
            
            temp->next=newnode; temp=newnode;
           }
           return dummy->next;
       
    }
};