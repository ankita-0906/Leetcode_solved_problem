class Solution {
public:
//------------------------memorisation-------------------------------------
int solve(vector<int>& nums,int index,vector<int>&dp){
       if(index<0) return 0;
       if(dp[index]!=-1) return dp[index];

       int incl=nums[index]+solve(nums,index-2,dp);
       int excl=0+solve(nums,index-1,dp);
       return dp[index]=max(incl,excl);
}
//-----------------------------tabulation-------------------------------------------------
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
//--------------------------space optimization---------------------------------------
int space(vector<int>&nums){
    int n=nums.size();
    int prev1=nums[0],prev2=0;
    for(int i=1;i<n;i++){
      int incl=nums[i]+prev2;
      int excl=0+prev1;
      int curr=max(incl,excl);
      prev2=prev1; prev1=curr;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<int>dp(n,-1);
        //int cnt=solve(nums,n-1,dp);
       // int cnt=tabsolve(nums,dp);
        int cnt=space(nums);
        return cnt;
    }
};