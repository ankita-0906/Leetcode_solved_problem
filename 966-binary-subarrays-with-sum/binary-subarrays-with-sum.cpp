class Solution {
public:
    int solve(vector<int>& nums, int goal,int n){
      int left=0, right=0,sum=0,cnt=0;
     while(right<n){
      sum=sum+nums[right];
     
      while(left<=right &&sum>goal){
        sum=sum-nums[left]; left++;
      }
       if(sum<=goal) cnt=cnt+right-left+1;
       right++;
     } 
     return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
     int n=nums.size();
      int a=solve(nums,goal,n);
      int b=solve(nums,goal-1,n);
      return a-b;
    }
};