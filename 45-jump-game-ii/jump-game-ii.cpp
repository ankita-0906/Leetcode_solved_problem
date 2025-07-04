class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();int right=INT_MIN;
        int step=0,l=0,r=0;
        while(r<n-1){
         
         for(int i=l;i<=r;i++){
            right=max(i+nums[i],right);
         }
          l=r+1,r=right;
         
         step++;
        }
        return step;
    }
};