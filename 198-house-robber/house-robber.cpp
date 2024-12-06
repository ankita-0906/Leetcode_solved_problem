class Solution {
public:
int solve(vector<int>& nums,int index,vector<int>&dp){
       if(index<0) return 0;
       if(dp[index]!=-1) return dp[index];

       int incl=nums[index]+solve(nums,index-2,dp);
       int excl=0+solve(nums,index-1,dp);
       return dp[index]=max(incl,excl);
}
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<int>dp(n,-1);
        int cnt=solve(nums,n-1,dp);
        return cnt;
    }
};