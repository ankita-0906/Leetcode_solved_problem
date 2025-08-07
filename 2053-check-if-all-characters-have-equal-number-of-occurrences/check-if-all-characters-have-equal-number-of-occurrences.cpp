class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26]={0};
        for(int i=0;i<s.length();i++) freq[s[i]-'a']++;

        int target=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            else if(target==0) target=freq[i];
            else if(target!=freq[i]) return false;
        }
        return true;
    }
};