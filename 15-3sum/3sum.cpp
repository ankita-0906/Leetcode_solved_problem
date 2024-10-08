class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =nums.size();
        set<vector<int>>st;
        sort( nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
              if(nums[i]+nums[j]+nums[k]==0) {
                vector<int>temp={nums[i],nums[j],nums[k]};
                st.insert(temp);
                k--;j++;
              }
              else if(nums[i]+nums[j]+nums[k]>0) k--;
              else j++;
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans ;
    }
};