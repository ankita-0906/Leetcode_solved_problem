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
   void solve(TreeNode* root,vector<string>&ans,string op){
    if(root==NULL) return ;
    if(root->left==NULL && root->right==NULL){
        op=op+to_string(root->val);
        ans.push_back(op);
        return ;
    }
    op=op+to_string(root->val)+"->";
    
    solve(root->left,ans,op);
    solve(root->right,ans,op);
   }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans; string op;
        solve(root,ans,op);
        return ans;
    }
};