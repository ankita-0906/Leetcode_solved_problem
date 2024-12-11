class Solution {
public:
    int solve(vector<int>& coins,int index, int amount,vector<vector<int>>& dp){
        //base case
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
           if(dp[index][amount]!=-1) return dp[index][amount]; 
        
        int mini=INT_MAX;
        for(int i=index;i>=0;i--){
           int cnt=solve(coins,i,amount-coins[i],dp);
           if(cnt!=INT_MAX)
           mini=min(mini,cnt+1);
        }

     return dp[index][amount]=mini;
       
    }



    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(coins,n-1,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};