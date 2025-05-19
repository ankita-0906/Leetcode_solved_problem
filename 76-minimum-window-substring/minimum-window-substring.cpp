class Solution {
public:
    string minWindow(string s, string t) {

        int n=s.length(),m=t.length();
        unordered_map<char,int>mp;
        int cnt=0,len=INT_MAX;

        for(int i=0;i<m;i++) mp[t[i]]++;
        int i=0,start=-1;
        for(int j=0;j<n;j++){

            if(mp.find(s[j])!=mp.end() && mp[s[j]]>0){
               cnt++;
            }
            mp[s[j]]--;
            while(cnt==m){
                
                if(len>j-i+1){
                  len=j-i+1;
                  start=i;
                }
                
                mp[s[i]]++;
                if(mp[s[i]]>0) cnt--;
                i++;
            }
        }
        if(start==-1) return "";
        return s.substr(start,len);
    }
};