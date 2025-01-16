class Solution {
public:
void solve(vector<vector<int>>& ans,vector<int>& nums,int n,vector<int>& output,vector<bool>& hash){
if(n==output.size()){
  ans.push_back(output);
  return;
}

for(int i=0;i<n;i++){
    if(hash[i]==false){
    output.push_back(nums[i]);
    hash[i]=true;
    solve(ans,nums,n,output,hash);
    hash[i]=false;
    output.pop_back();
    }
}
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int n =nums.size();vector<bool>hash(n,false);
        solve(ans,nums,n,output,hash);
        return ans;
    }
};