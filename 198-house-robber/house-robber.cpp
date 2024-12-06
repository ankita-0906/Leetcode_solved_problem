class Solution {
public:
int solve(vector<int>& nums,int index,vector<int>&dp){
       if(index<0) return 0;
       if(dp[index]!=-1) return dp[index];

       int incl=nums[index]+solve(nums,index-2,dp);
       int excl=0+solve(nums,index-1,dp);
       return dp[index]=max(incl,excl);
}
int tabsolve(vector<int>&nums,vector<int>&dp){
    dp[0]=nums[0]; int incl=INT_MIN;
     for(int i=1;i<nums.size();i++){
        if(i>1) incl=nums[i]+dp[i-2];
        else incl=nums[i];
       int excl=0+dp[i-1];
        dp[i]=max(incl,excl);
     }
     return dp[nums.size()-1];
}
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<int>dp(n,-1);
        //int cnt=solve(nums,n-1,dp);
        int cnt=tabsolve(nums,dp);
        return cnt;
    }
};