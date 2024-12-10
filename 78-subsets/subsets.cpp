class Solution {
public:
    void solve(vector<int>& nums,int n,int i,vector<vector<int>>&op,vector<int>&output){
        if(i>=n){
            op.push_back(output);
            return;
        }
         output.push_back(nums[i]);
         solve(nums,n,i+1,op,output);
         output.pop_back();
         solve(nums,n,i+1,op,output);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>output;
        vector<vector<int>>op;
        solve(nums,n,0,op,output);
        
        return op;
    }
};