class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<guess.size();i++) mp1[secret[i]]++;
        for(int i=0;i<guess.size();i++) mp2[guess[i]]++;
        int i=0,cnt=0;
        while(i<secret.size() && i<secret.size()){
         if(secret[i]==guess[i]) cnt++;
         i++;
        }
        int diff=0;
        
        for(auto it : mp1){
         if(mp2.find(it.first) != mp2.end()){
        diff += min(it.second, mp2[it.first]);
       }
      }

        
        string s = to_string(cnt) + "A" + to_string(diff - cnt) + "B";

        return s;
    }
};