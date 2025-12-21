class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long>mp;
        long long total=0,maxi=0;
        for(int i=0;i<cost.size();i++){
            mp[s[i]]=mp[s[i]]+cost[i];
            maxi=max(maxi,mp[s[i]]);
            total=total+cost[i];
        }
        
        return total-maxi;
    }
};