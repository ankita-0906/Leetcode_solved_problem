class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum=0,cnt=0; int add=0;
        
        
        for(int i=0;i<n;i++){
            
             if(k>0 && nums[i]<0){
                sum=sum+abs(nums[i]);
                k--;
             }
             
             else if(k>0 && nums[i]>=0){
                int mini=nums[i];
                if(i!=0) mini= min(abs(nums[i]),abs(nums[i-1]));
                if(k%2!=0) add=2*mini;
                sum=sum+nums[i]; k=0;
             }
              else sum=sum+nums[i];
        }
        if(k>0){
              if(k%2!=0) add=2*abs(nums[n-1]);
        }
        return sum-add;
    }
};