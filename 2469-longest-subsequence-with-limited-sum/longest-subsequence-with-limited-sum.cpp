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
           int low=0,heigh=n-1,res=0;
           while(low<=heigh){
            int mid=(low+heigh)/2;
            if(prefix[mid]<=queries[i]) {
                res=mid+1; low=mid+1;
            }
            else heigh=mid-1;
           }
           ans[i]=res;
            
            
        }
        return ans;
    }
};