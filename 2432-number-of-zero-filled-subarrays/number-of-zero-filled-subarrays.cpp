class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=-1,j=0; long long cnt=0;
        while(j<n){
            if(nums[j]!=0) i=j;
            else cnt=cnt+j-i;
            j++;
        }
        return cnt;
    }
};