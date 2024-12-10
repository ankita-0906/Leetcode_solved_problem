class Solution {
public:
    bool solve(vector<int>& arr,vector<vector<int>>&dp,int i,int target){
        //base case
         if(target==0) return true;
         if(i==0) return target==arr[i];
        if(dp[i][target] !=-1) return dp[i][target];
        bool exclude=solve(arr,dp,i-1,target);
        bool include=false;
        if(target>=arr[i]) include=solve(arr,dp,i-1,target-arr[i]);
        return dp[i][target]=include|| exclude;
    }


    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++) sum=sum+nums[i];
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans=solve(nums,dp,n-1,target);
        return ans;
    }
};