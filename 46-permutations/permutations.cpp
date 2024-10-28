class Solution {
public:
void solve(vector<vector<int>>& ans,vector<int>& nums,int n,vector<int>& output){
 // base case
 if(output.size()==n) {
    ans.push_back(output);
    return;
 }

 for(int i=0;i<n;i++){
    if(nums[i]!=-100){
        int temp=nums[i];
        output.push_back(nums[i]);
        nums[i]=-100;
        solve(ans,nums,n,output);
        nums[i]=temp;
        output.pop_back();
    }
 }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int n =nums.size();
        solve(ans,nums,n,output);
        return ans;
    }
};