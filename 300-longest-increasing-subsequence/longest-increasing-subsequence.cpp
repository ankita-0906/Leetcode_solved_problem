class Solution {
public:

    int solve(vector<int>& nums,int index,int prev,vector<vector<int>>&dp){
        if(index<0) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];

        int not_take=0+solve(nums,index-1,prev,dp);
        int take =0;
        if(prev==-1 || nums[index]<nums[prev] )
         take =1+solve(nums,index-1,index,dp);
        return dp[index][prev+1]=max(take,not_take); 
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,n-1,-1,dp);
    }
};