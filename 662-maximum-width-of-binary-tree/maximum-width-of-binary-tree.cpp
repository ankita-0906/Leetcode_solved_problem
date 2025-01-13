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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});int ans=0,first,last;
        while(!q.empty()){
          int size=q.size(); int left=q.front().second;
           for(int i=0;i<size;i++){
             auto it=q.front(); q.pop();
             long long curr=it.second-left;
             if(i==0) first=curr;
             if(i==size-1)  last=curr;
             if(it.first->left) q.push({it.first->left,2*curr+1});
             if(it.first->right) q.push({it.first->right,2*curr+2});
           }
           ans=max(ans,last-first+1);
        }
        return ans;
    }
};