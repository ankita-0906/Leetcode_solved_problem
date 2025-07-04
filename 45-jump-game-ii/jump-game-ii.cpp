class Solution {
public:
int solve(int index, vector<int>& arr, vector<int>& dp) {
    int n = arr.size();
    if (index >= n - 1) return 0;
    if (dp[index] != -1) return dp[index];

    int mini = INT_MAX;
    for (int i = index+1; i <= index+arr[index]; i++) { 
       
            int count =  solve( i, arr, dp);
            if (count != INT_MAX) {
                mini = min(mini, count + 1);
            }
         
    }
    return dp[index] = mini;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};