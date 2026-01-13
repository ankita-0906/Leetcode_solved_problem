class Solution {
public:
struct cmp {
        bool operator()(pair<int,string> &a, pair<int,string> &b) {
           
            if (a.first == b.first)
                return a.second < b.second; 
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto &word: words){
            mp[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,
       cmp>pq;

       for(auto it: mp){
        pq.push({it.second,it.first});
        if(pq.size()>k) pq.pop();
       }
       vector<string>ans;
      
       while(!pq.empty()){
        auto it =pq.top(); pq.pop();
        ans.push_back(it.second);
       }
       reverse(ans.begin(), ans.end());
     

       return ans;
    }
};