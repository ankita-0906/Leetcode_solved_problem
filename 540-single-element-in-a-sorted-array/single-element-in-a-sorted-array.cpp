class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n-2,mid, ans;

        if(n==1) return nums[0];
         if(nums[0]!=nums[1]) return nums[0];
         if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(low<=high){
          mid=low+(high-low)/2;
        //   if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
        //    return nums[mid];
          
          if(mid%2==0){
            if(nums[mid]==nums[mid+1]) low=mid+1;
            else {
                ans=mid;
                high=mid-1;
            }
          }
          else {
             if(nums[mid]==nums[mid+1]) {
                ans=high;
                high=mid-1;
             }
              
             else low=mid+1;
          }
        }
        return nums[ans];
    }
};