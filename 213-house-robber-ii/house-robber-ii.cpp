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
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>arr1(nums.begin(),nums.end()-1);
        vector<int>arr2(nums.begin()+1,nums.end());
        vector<int>dp1(n-1,-1);  vector<int>dp2(n-1,-1);
        int cnt=max(solve(arr1,arr1.size()-1,dp1),solve(arr2,arr2.size()-1,dp2));
        return cnt;
    }
};