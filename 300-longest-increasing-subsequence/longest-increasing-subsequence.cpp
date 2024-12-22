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
   //----------------------tabulation----------------------------------------

   int solvetab(vector<int>& nums,int n){
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      int maxi=INT_MIN;
      for(int index=n-1;index>=0;index--){
        for(int prev=index-1;prev>=-1;prev--){
            int non_take=dp[index+1][prev+1];
            int take=0;
            if(prev==-1 || nums[index]>nums[prev])
            take=1+dp[index+1][index+1];
            dp[index][prev+1]=max(take,non_take) ;
            maxi=max(maxi,dp[index][prev+1]);
        }
      }

      return maxi;
   }
    

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        //return solve(nums,n-1,-1,dp);
        return solvetab(nums,n);
      
    }
};