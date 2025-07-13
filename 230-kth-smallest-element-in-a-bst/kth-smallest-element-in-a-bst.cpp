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
   void solve(TreeNode* root, int k,int& cnt,int &ans){
    //  if(root==NULL) return ;
    if(root->left){
        solve(root->left,k,cnt,ans);
     cnt++;
    }
    else cnt++;
     if(cnt==k) {
        ans=root->val;
        return;
     }
     if(root->right)solve(root->right,k,cnt,ans);
   }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0,ans=-1;
     solve(root,k,cnt,ans);
     return ans;
    }
};