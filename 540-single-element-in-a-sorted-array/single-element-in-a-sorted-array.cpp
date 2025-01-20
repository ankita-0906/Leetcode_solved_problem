class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,ans;
        if(nums[low]==nums[high]) return nums[low];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid%2==0){
                if(mid==n-1) return nums[n-1];
                else if(nums[mid]==nums[mid+1]){
                   
                    low=mid+1;
                }
                 
                 else {

                    high=mid-1;
                 }
            }
            else{
                 if(nums[mid]==nums[mid-1]) low=mid+1;
                 else high=mid-1;
            }
        }
        return nums[low];
    }
};