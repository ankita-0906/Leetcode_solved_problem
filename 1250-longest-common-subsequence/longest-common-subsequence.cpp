class Solution {
public:
    int solve(string &s1,string &s2,int id1,int id2,vector<vector<int>>&dp){
        if(id1<0 || id2<0) return 0;
        if(dp[id1][id2]!=-1)  return dp[id1][id2];
        if(s1[id1]==s2[id2]) return 1+solve(s1,s2,id1-1,id2-1,dp);

        return dp[id1][id2]=max(solve(s1,s2,id1-1,id2,dp),solve(s1,s2,id1,id2-1,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        int ans=solve(text1,text2,n1-1,n2-1,dp);
        return ans;
    }
};