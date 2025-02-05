class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1,cnt=1;
        while(j<n){
          if(nums[i]==nums[j] && cnt<2){
            cnt++;
            nums[i+cnt-1]=nums[j];
          
          } 
          else if(nums[i]!=nums[j]){
            nums[i+cnt]=nums[j];
            i=i+cnt;
            cnt=1;
          }
          
          j++;
        }
        return i+cnt;
    }
};