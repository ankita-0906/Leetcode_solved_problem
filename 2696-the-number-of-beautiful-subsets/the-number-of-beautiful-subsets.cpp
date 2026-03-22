class Solution {
public:
    int rec(int index,vector<int>&op,int n,vector<int>&nums,int k){
        if(n==index){
            if(op.size()>=1) return 1;
         
         return 0;
        } 
        
        // not take
        int not_take=rec(index+1,op,n,nums,k);
        
        int take=0;
        if(find(op.begin(),op.end(),nums[index]+k)==op.end() && 
        find(op.begin(),op.end(),nums[index]-k)==op.end()){
            op.push_back(nums[index]);
            take=rec(index+1,op,n,nums,k);
            op.pop_back();
        }
     return not_take+take;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>op;int n=nums.size();
        return rec(0,op,n,nums,k);
    }
};