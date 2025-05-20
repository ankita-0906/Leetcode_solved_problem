class Solution {
public:
    void solve(vector<int>& candidates, int index, int target, vector<int>& path, vector<vector<int>>& res) {
        if(index==candidates.size()){
            if(target==0) res.push_back(path);
            return ;
        }

        // Pick the current element (only if it doesn’t exceed target)
        if (candidates[index] <= target) {
            path.push_back(candidates[index]);
            solve(candidates, index + 1, target - candidates[index], path, res);
            path.pop_back();
        }

        // Skip to next distinct number (to avoid duplicates)
        int next = index + 1;
        while (next < candidates.size() && candidates[next] == candidates[index]) next++;

        solve(candidates, next, target, path, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Important for skipping duplicates
        vector<vector<int>> res;
        vector<int> path;
        solve(candidates, 0, target, path, res);
        return res;
    }
};
