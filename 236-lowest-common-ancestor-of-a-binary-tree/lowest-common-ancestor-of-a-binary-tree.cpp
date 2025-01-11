/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root,vector<TreeNode*>&ans1,vector<TreeNode*>&ans2,
    vector<TreeNode*>&op,TreeNode* p,TreeNode* q){
      if(root==NULL){
         return ;
      }
	  
      op.push_back(root);
      solve(root->left,ans1,ans2,op,p,q);
      solve(root->right,ans1,ans2,op,p,q);
      if(root==p){
		 
		  ans1=op;op.pop_back();
		  return;
	  }
      if(root==q){
		 
		  ans2=op;op.pop_back();
		  return;
	  }
      op.pop_back();
      
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         vector<TreeNode*>op;vector<TreeNode*>ans1,ans2;
         solve(root,ans1,ans2,op,p,q);
         int i=0; TreeNode*value;
         while(i<ans1.size() && i<ans2.size()){
            if(ans1[i]==ans2[i])value=ans1[i];
            i++;
         }
         return value;
    }
};