class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        priority_queue<pair<int,int>>maxh;
        int n=nums.size(),i=0;
        while(i<n){
            int diff=abs(nums[i]-x);
            maxh.push({diff,nums[i]});
            if(maxh.size()>k) maxh.pop();
            i++;
        }
        vector<int>ans;
        while(!maxh.empty()){
           ans.push_back(maxh.top().second);
           maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};