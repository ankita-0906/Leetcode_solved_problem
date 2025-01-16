class Solution {
public:
void solve(vector<vector<int>>& ans,vector<int>& nums,int n,int index){
if(index==n) {
  ans.push_back(nums);
  return;
}
for(int i=index;i<n;i++){
    swap(nums[index],nums[i]);
    solve(ans,nums,n,index+1);
     swap(nums[index],nums[i]);
}

}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int n =nums.size();
        solve(ans,nums,n,0);
        return ans;
    }
};