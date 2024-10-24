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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>arr;
        ListNode*temp,*zero;
        temp=head->next;zero=temp;
        int sum;
        while(temp!=NULL){
         sum=0;
         while( temp->next!=NULL && zero->val!=0){
            sum=sum+zero->val;
            zero=zero->next;
            temp=zero;
         }
         arr.push_back(sum);
        zero=zero->next;
        temp=zero;
        }
     ListNode* first = new ListNode(arr[0]);  // Initialize the first node
     ListNode* tail = first;

    for (int i = 1; i < arr.size(); i++) {
        ListNode* newnode = new ListNode(arr[i]);  
        tail->next = newnode;  
        tail = newnode;  
    }
        return first;
    }
};