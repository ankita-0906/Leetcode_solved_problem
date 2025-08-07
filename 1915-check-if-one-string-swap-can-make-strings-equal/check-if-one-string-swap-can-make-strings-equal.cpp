class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int i=0,cnt=0;
        int freq1[26]={0}; int freq2[26]={0};

        for(int i=0;i<n;i++) freq1[s1[i]-'a']++;
        for(int i=0;i<n;i++) freq2[s2[i]-'a']++;
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        while(i<n){
          if(s1[i]!=s2[i]) cnt++;
          i++;
        }
        if(cnt==0 || cnt==2) return true;
        return false;
    }
};