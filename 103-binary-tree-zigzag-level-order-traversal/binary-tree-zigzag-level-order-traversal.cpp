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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans; if (root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool l_to_r=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>arr(size);
            for(int i=0;i<size;i++){
              TreeNode* ele=q.front(); q.pop();
              int index=l_to_r?i:(size-i-1);
              arr[index]=ele->val;
              if(ele->left) q.push(ele->left);
              if(ele->right) q.push(ele->right);
            }
            l_to_r=!l_to_r;
            ans.push_back(arr);
        }
        return ans;
    }
};