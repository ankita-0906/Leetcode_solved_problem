class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low=0,high=n-1, ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[mid+1]) low=mid+1;
            else {
                ans=mid; high=mid-1;
            }
        }
        return ans;
    }
};