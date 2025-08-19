class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.length();
        int j=1,cnt=1,maxi=-1;
        while(j<n){
          if(s[j]==s[j-1]+1){
            cnt++;
          }
          else{
            maxi=max(maxi,cnt);
            cnt=1;
          }
          j++;
        }
         maxi=max(maxi,cnt);
        return maxi;
    }
};