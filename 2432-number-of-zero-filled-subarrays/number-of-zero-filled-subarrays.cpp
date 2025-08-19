class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long cnt=0;
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
          if(nums[j]==0 && nums[i]!=0){
            i=j; cnt=cnt+j-i+1;
          }
          else if(nums[i]==0 && nums[j]==0) cnt=cnt+j-i+1;
          else if(nums[j]!=0) i=j;
          j++;
        }
        return cnt;
    }
};