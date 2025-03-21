/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */ 
 class BSTiterator {
 private:
    stack<TreeNode* >st; bool reverse;
public:

    BSTiterator(TreeNode* root,bool isreverse){
      reverse=isreverse;
      pushall(root,reverse);
    }
    void pushall(TreeNode* root,bool reverse){
        while(root){
            st.push(root);
            if(reverse) root=root->right;
            else root=root->left;
        }
    }
     int next(){
        TreeNode* node=st.top(); st.pop();
        if(reverse) pushall(node->left,reverse);
        else pushall(node->right,reverse);
        return node->val;
     }
};
class Solution {
   public:
    bool findTarget(TreeNode* root, int k) {
     BSTiterator l(root,false);
        BSTiterator r(root,true);
        int left=l.next();
        int right=r.next();
        while(left<right){
            if(left+right==k) return true;
            else if(left+right>k) right=r.next();
            else left=l.next();
        }
        return false;
    }
};