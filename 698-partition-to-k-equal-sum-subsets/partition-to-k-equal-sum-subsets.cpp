class Solution {
public:
   bool rec(int index,int target,int n,vector<int>& nums,vector<int>& bucket){
    if(index==n) return true;

    for(int i=0;i<bucket.size();i++){
        if(nums[index]+bucket[i]>target) continue;

        bucket[i]=bucket[i]+nums[index];

        if(rec(index+1,target,n,nums,bucket)) return true;
          bucket[i]=bucket[i]-nums[index];
        
        if(bucket[i]==0) break;
    }
    return false;
   }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(sum%k!=0) return false;
        int target=sum/k;
        
        vector<int>bucket(k,0);
        return rec(0,target,n,nums,bucket);
    }
};