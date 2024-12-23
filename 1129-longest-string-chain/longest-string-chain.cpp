class Solution {
public:

static bool compareByLength(const string &a, const string &b) {
    return a.size() < b.size();
}
bool compare(string s1,string s2){
    int n1=s1.length(),n2=s2.length();
    int i=0,j=0,cnt=0;
    if((n1-n2) !=1) return false;
    while(i<n1 && j<n2){
      if(s1[i]==s2[j]){
        i++;j++; cnt++;
      }
      else i++;
    }
    if(cnt==n2) return true;
    return false;

}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),compareByLength);
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                maxi=max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};