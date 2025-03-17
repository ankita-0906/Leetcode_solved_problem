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
    int solve(TreeNode* root){
       if(root==NULL) return 0;
        int lefti=0,righti=0;
        if(root->left){
            lefti=solve(root->left);
        }
        if(root->right){
            righti=solve(root->right);
        }
        return lefti+righti+1;
    }
    int countNodes(TreeNode* root) {
      return solve(root);
    }
};