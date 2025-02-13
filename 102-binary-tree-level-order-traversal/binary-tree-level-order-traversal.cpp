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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q; q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>list;
            for(int i=0;i<size;i++){
                TreeNode* ele=q.front();  q.pop();
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
                list.push_back(ele->val);
            }
            ans.push_back(list);
        }
        return ans;
    }
};