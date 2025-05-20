class Solution {
public:
    void solve(vector<int>& candidates, int index, vector<int>& path, vector<vector<int>>& res) {
        if(index==candidates.size()){
             res.push_back(path);
            return ;
        }

        // Pick the current element (only if it doesn’t exceed target)
        
            path.push_back(candidates[index]);
            solve(candidates, index + 1,  path, res);
            path.pop_back();
     

        // Skip to next distinct number (to avoid duplicates)
        int next = index + 1;
        while (next < candidates.size() && candidates[next] == candidates[index]) next++;

        solve(candidates, next, path, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& candidates) {
        sort(candidates.begin(), candidates.end());  // Important for skipping duplicates
        vector<vector<int>> res;
        vector<int> path;
        solve(candidates, 0, path, res);
        return res;
    }
};