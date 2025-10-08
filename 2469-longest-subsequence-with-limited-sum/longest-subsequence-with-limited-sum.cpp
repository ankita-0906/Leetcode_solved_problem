class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n=nums.size(),m=queries.size();
        vector<int>ans(m),prefix(n);
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<n;i++){
         sum=sum+nums[i];
         prefix[i]=sum;
        }

        for(int i=0;i<m;i++){
            int res=0;
            for(int j=0;j<n;j++){
                if(prefix[j]<=queries[i]) res=j+1;
                else break;
            }
            ans[i]=res;
        }
        return ans;
    }
};