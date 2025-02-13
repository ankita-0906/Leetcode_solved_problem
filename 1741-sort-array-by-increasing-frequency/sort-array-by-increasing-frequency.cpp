class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size(),i=0;
        unordered_map<int,int>mp;
        while(i<n){
         mp[nums[i]]++;
         i++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it=mp.begin();it!=mp.end();it++){
            q.push({-(it->second),it->first});
        }
        vector<int>ans;
        while(!q.empty()){
            auto it=q.top();
            int freq=-it.first;
          while(freq--) ans.push_back(it.second);
          q.pop();
        }
        return ans;
    }
};