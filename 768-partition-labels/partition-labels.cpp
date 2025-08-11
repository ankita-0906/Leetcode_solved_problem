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
        vector<int>ans;
        sort(arr.begin(),arr.end());
        int start=arr[0].first,end=arr[0].second;
        ans.push_back(end-start+1);
        for(int i=1;i<arr.size();i++){
             if (arr[i].first <= end) {
              if (arr[i].second > end) {
              int len = ans.back();
              ans.back() = arr[i].second - end + len; 
              end = arr[i].second;
            }
        }
        else {
         ans.push_back(arr[i].second - arr[i].first + 1);
         end=arr[i].second ;
        }
        }
        return ans;
    }
};