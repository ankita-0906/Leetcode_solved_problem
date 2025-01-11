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

    void solve(TreeNode* root,vector<string>&ans,string &op){
      if(root==NULL){
         return ;
      }
      if(root->left==NULL && root->right==NULL){
        op=op+to_string(root->val);
        ans.push_back(op); op.erase(op.size() - to_string(root->val).size());
         return ;
      }
      op=op+to_string(root->val)+"->";
      solve(root->left,ans,op);
      solve(root->right,ans,op);
      op.erase(op.size() - to_string(root->val).size() - 2);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string>ans; string op;
        solve(root,ans,op);
        return ans;
    }
};