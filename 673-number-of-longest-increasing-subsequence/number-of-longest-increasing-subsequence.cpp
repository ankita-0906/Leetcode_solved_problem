class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
         vector<int>dp(n,1); vector<int>cnt(n,1);int maxi=1;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j]; maxi=max(maxi,dp[i]);
                }
                else if(dp[i]==1+dp[j]){
                   cnt[i]=cnt[j]+cnt[i];
                }
            }
        }
        int last=-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                count=count+cnt[i];
            }
        }
        return count;
    }
};