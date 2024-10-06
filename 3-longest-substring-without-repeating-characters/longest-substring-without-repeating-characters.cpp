class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.length(); int maxi=0;
        int i=0,j=0,len=0; 
        unordered_map<char,int>mpp;
        while(i<n &&j<n){
          mpp[s[j]]++;
          while(mpp[s[j]]>1 && i<j){
            mpp[s[i]]--;
            i++;
          }
          len=j-i+1;
          maxi=max(len,maxi);
          j++;
        }
        
        return maxi;
    }
};