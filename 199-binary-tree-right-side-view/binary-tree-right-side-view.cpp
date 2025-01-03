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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans; if(root==NULL) return ans;
         queue<pair<int,TreeNode*>>q;
         map<int,int>mp;
         q.push({0,root});
         while(!q.empty()){
        auto ele=q.front();       q.pop();
        int x=ele.first;
        auto node=ele.second;
         mp[x]=node->val;
        if(node->left) q.push({x+1,node->left});
        if(node->right) q.push({x+1,node->right});
    }
    
    for(auto i:mp){
     ans.push_back(i.second);
    }
    return ans;
    }
};