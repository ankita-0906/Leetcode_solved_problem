class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.length();i++) {
            char ch=s[i];
            if(mp.find(ch)==mp.end()){
                mp[ch].first=i;
                mp[ch].second=i;
            }
            else  mp[ch].second=i;
        }

        vector<pair<int,int>>arr;
        for(auto it:mp){
            auto index=it.second;
            arr.push_back({index.first,index.second});
        }
        sort(arr.begin(), arr.end());

        // Step 4: Merge intervals & get partition sizes
        vector<int> ans;
        int start = arr[0].first, end = arr[0].second;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i].first <= end) { // overlap
                end = max(end, arr[i].second);
            } else { // no overlap → push result
                ans.push_back(end - start + 1);
                start = arr[i].first;
                end = arr[i].second;
            }
        }
        ans.push_back(end - start + 1);
        return ans;
    }
};