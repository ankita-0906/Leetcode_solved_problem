class Solution {
public:
    int solve(vector<int>&cost,int n,int curr,vector<int>&dp){
        //base case
        if(curr>=n) return 0;
        if(dp[curr]!=-1) return dp[curr];
       int left=solve(cost,n,curr+1,dp);
       int right=solve(cost,n,curr+2,dp);
       if(curr==0) return min(left,cost[curr]+right);
       return dp[curr]=cost[curr]+min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        vector<int>dp(n,-1);
        int a=n;
        int count=solve(cost,n,0,dp);
        return count;
    }
};