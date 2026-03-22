class Solution {
public:
void rec(int index,int n,vector<int>& nums,
vector<int>&op, set<vector<int>>&temp){
    if(index==n){
        if(op.size()>=2)
        temp.insert(op);
        return;
    }
    //not take
    rec(index+1,n,nums,op,temp);

    // take 
    if(op.size()==0){
        op.push_back(nums[index]);
         rec(index+1,n,nums,op,temp);
         op.pop_back();
    }
    else if(nums[index]>=op.back()){
        op.push_back(nums[index]);
         rec(index+1,n,nums,op,temp);
         op.pop_back();
    }
      
}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      
        vector<int>op;
        set<vector<int>>temp;
        int n=nums.size();
        rec(0,n,nums,op,temp);
          vector<vector<int>>ans(temp.begin(),temp.end());
        return ans;
    }
};