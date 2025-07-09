class Solution {
public:
void solve(int n,int k,int index,vector<vector<int>>&ans,vector<int>&output){
  if(output.size()==k){
    ans.push_back(output);
    return;
  }
  
  for(int i=index+1;i<=n;i++){
    output.push_back(i);
    solve(n,k,i,ans,output);
    output.pop_back();
  }

}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>output;
        for(int i=1;i<=n;i++){
         output.push_back(i);
          solve(n,k,i,ans,output);
          output.pop_back();
        }
        return ans;
    }
};