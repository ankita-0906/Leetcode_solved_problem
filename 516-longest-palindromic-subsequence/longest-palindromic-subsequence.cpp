class Solution {
public:
   int solve(string &s1,string &s2,int id1,int id2,vector<vector<int>>&dp){
        if(id1<0 || id2<0) return 0;
        if(dp[id1][id2]!=-1)  return dp[id1][id2];
        if(s1[id1]==s2[id2]) return 1+solve(s1,s2,id1-1,id2-1,dp);

        return dp[id1][id2]=max(solve(s1,s2,id1-1,id2,dp),solve(s1,s2,id1,id2-1,dp));
    }


    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,t,n-1,n-1,dp);
    }
};