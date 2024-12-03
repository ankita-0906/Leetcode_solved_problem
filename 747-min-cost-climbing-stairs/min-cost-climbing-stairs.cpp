class Solution {
public:
    int solve(vector<int>&cost,int n,int a,vector<int>&dp){
        //base case
        if(n==0 || n==1) return cost[n];
        if(n!=a && dp[n]!=-1) return dp[n];
        int left=solve(cost,n-1,a,dp);
        int right=solve(cost,n-2,a,dp);
        if(n==a) return min(left,right);
        return dp[n]=cost[n]+min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        vector<int>dp(n,-1);
        int a=n;
        int count=solve(cost,n,a,dp);
        return count;
    }
};