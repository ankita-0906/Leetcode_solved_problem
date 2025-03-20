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
        TreeNode*solve(TreeNode*root){
           while (root->right) {
            root = root->right;
        }
        return root;
        }
        TreeNode* helper(TreeNode*root){
          if(root->left==NULL && root->right ==NULL) return NULL;
          if( root->left==NULL) return root->right;
          else if( root->right==NULL) return root->left;
          TreeNode*rightchild=root->right;
          TreeNode*last=solve(root->left);
          last->right=rightchild;
          return root->left;
        }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode*dummy=root;
        if(root==NULL) return NULL;
        if( root->val==key){
            return helper(root);
        }
        while(root){
         if(root->val>key){
            if(root->left &&root->left->val==key){
                root->left=helper(root->left);
                break;
            }
            else 
            root=root->left;
        }
        else {
            if(root->right && root->right->val==key){
                root->right=helper(root->right);
                break;
            }
            else 
            root=root->right;
        }
        }
        return dummy;
        
    }
};