class Solution {
public:
   int solve(string &s1,string &s2,int id1,int id2,vector<vector<int>>&dp){
        if(id1<0 || id2<0) return 0;
        if(dp[id1][id2]!=-1)  return dp[id1][id2];
        if(s1[id1]==s2[id2]) return 1+solve(s1,s2,id1-1,id2-1,dp);

        return dp[id1][id2]=max(solve(s1,s2,id1-1,id2,dp),solve(s1,s2,id1,id2-1,dp));
    }

    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m =s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans= solve(s1,s2,n-1,m-1,dp);
        return n-ans+m-ans;
    }
};