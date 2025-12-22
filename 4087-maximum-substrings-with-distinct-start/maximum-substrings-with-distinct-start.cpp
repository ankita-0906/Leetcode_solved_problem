class Solution {
public:
    int maxDistinct(string s) {
        int n=s.length();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[s[i]]++;

        return mp.size();
    }
};