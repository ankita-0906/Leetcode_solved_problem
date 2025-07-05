class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, vector<pair<int, int>>> mp; // col -> vector of {row, val}

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front(); q.pop();
            int col = pos.first, row = pos.second;
            mp[col].push_back({row, node->val});

            if (node->left)  q.push({node->left, {col - 1, row + 1}});
            if (node->right) q.push({node->right, {col + 1, row + 1}});
        }

        vector<vector<int>> ans;
        for (auto& [col, nodes] : mp) {
            sort(nodes.begin(), nodes.end()); // sort by row, then val
            vector<int> colVals;
            for (auto& [row, val] : nodes)
                colVals.push_back(val);
            ans.push_back(colVals);
        }
        return ans;
    }
};
