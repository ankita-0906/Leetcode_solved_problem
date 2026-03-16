class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size(); int ans=-1;
        vector<long long>sum(n,0);
        vector<long long>product(n,1);
       
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
       if(sum[n-1]==product[n-1]) ans=n-1;
        for(int i=n-2;i>=0;i--) {
            
            
            if(product[i+1]>sum[n-1]) break;

          if(nums[i+1] != 0 && product[i+1] > sum[n-1] / nums[i+1]) break;
             product[i]=product[i+1]*nums[i+1];

             if(sum[i]==product[i]) ans=i;
        }

       
        return ans;
    }
};