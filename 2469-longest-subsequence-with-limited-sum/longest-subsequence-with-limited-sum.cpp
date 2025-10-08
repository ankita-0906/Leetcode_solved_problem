class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n=nums.size(),m=queries.size();
        vector<int>ans(m);
        sort(nums.begin(),nums.end());
        for(int i=0;i<m;i++){
            int sum=0,res=0;
            for(int j=0;j<n;j++){
              sum=sum+nums[j];
              if(sum<=queries[i]) res=j+1;
              else break;
            }
            ans[i]=res;
        }
        return ans;
    }
};