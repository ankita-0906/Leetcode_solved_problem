class Solution {
public:
    int solve(vector<int>&arr,int n,int a,vector<int>&dp){
        if(n==0) return 0;
        if(n==1) return arr[a-n];
        if(dp[a-n]!=-1) return dp[a-n];
        int left=solve(arr,n-2,a,dp);
        int right=solve(arr,n-1,a,dp);
        if(n==a) return min(right,arr[a-n]+left);
        return dp[a-n] =arr[a-n]+min(left,right);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        vector<int>dp(n,-1);
        int a=n;
        int count=solve(cost,n,a,dp);
        return count;
    }
};