class Solution {
    private:
    void solve(vector<int>&candidates,vector<vector<int>>&ans,int target,int index,vector<int>output)
    {
        if(index== candidates.size())
        {   if(target==0){
            ans.push_back(output);
           }
            return;
        }
        if(target>=candidates[index])
        {
        
        output.push_back(candidates[index]);

        solve(candidates,ans,target-candidates[index],index,output);
        output.pop_back();
        
        }
        
         solve(candidates,ans,target,index+1,output);
         
        
       
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
         int index=0;
         vector<int>output;
        solve(candidates,ans,target,index,output);
        return ans;
        
    }
};