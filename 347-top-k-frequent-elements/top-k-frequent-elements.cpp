class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        int n=nums.size(),i=0;
        while(i<n){
            mp[nums[i]]++;
         i++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
       for(auto it=mp.begin();it!=mp.end();it++){
          q.push({it->second,it->first});
          if(q.size()>k) q.pop();
       }
       vector<int>ans;
       while(!q.empty()){
        ans.push_back(q.top().second);
        q.pop();
       }
       return ans;

    }
};