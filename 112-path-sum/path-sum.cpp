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
bool solve(TreeNode* root, int target,int sum){
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL) {
        if(sum+root->val==target) return true;
        return false;
    }
   
    return solve(root->left,target,sum+root->val) ||
    solve(root->right,target,sum+root->val);
    
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return solve(root,targetSum,sum);
    }
};