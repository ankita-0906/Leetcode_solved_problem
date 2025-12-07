class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.length(); int maxi=0;
        int i=0,j=0,len=0; 
        unordered_map<char,int>mp;
        while(j<n){
         ;
          while(mp.find(s[j])!=mp.end() && i<j){
           mp.erase(s[i]);
            i++;
          }
          mp[s[j]]++;
          len=j-i+1;
          maxi=max(len,maxi);
          j++;
        }
        
        return maxi;
    }
};