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
class Solution {
public:
    // void inorder(TreeNode* root,vector<int>&ans){
    //     if(root==NULL) return;
        
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    // }


    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int>ans; inorder(root,ans);
        // return ans;

        vector<int>ans;   stack<TreeNode*>st; if(root==NULL) return ans;  
        TreeNode* curr=root;
        while(!st.empty() || curr!=NULL){
            if(curr==NULL){
                    TreeNode* ele=st.top(); 
                ans.push_back(ele->val);     st.pop();
                curr=ele->right;
            }
            else{
                st.push(curr);
                curr=curr->left;
            }
        }
        return ans;
    }
};