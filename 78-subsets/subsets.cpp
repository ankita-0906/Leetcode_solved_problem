class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n =nums.size();
        long long subset=pow(2,n);
        vector<vector<int>>ans;
        
        for(long i=0;i<subset;i++){
            vector<int>output;
            for(int j=0;j<n;j++){
             if(i&(1<<j)) 
             output.push_back(nums[j]);
            
            }
            ans.push_back(output);
        }
        return ans;
    }
};