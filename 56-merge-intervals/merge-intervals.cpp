class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
       int n =nums.size(); int start,end,j;
       int i=1;
       ans.push_back(nums[0]);
       
       while(i<n){
        end=ans.back()[1];
         if(nums[i][0]<=end){
            end=max(end,nums[i][1]);
            ans.back()[1]=end;
         }
         else ans.push_back(nums[i]);
         i++;
       }
       
        return ans;
    }
};