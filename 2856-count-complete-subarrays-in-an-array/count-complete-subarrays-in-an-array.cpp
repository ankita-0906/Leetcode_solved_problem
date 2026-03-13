class Solution {
public:
 int count(vector<int>& nums,int k){
        int cnt=0;
       unordered_map<int,int>mpp; int i=0;
      
        for(int j=0;j<nums.size();j++){
          mpp[nums[j]]++;
          while(mpp.size()>k){
           mpp[nums[i]]--; 
           if(mpp[nums[i]]==0) mpp.erase(nums[i]);
           i++;
          }
          cnt=cnt+j-i+1;
        }
        return cnt;
 }
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int k=mp.size();
       
        return count(nums,k)-count(nums,k-1);
    }
};