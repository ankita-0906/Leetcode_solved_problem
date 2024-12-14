class Solution {
public:
   int solve(string s1,int i,string s2,int j,vector<vector<int>>&dp){
    if (j < 0) return 1;  
    if (i < 0) return 0;  

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]) return dp[i][j]=solve(s1,i-1,s2,j,dp)+solve(s1,i-1,s2,j-1,dp);
    else return dp[i][j]=solve(s1,i-1,s2,j,dp);
   }



    int numDistinct(string s, string t) {
        int n1=s.length(),n2=t.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(s,n1-1,t,n2-1,dp);
    }
};