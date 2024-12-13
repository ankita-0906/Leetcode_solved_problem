class Solution {
public:
    int solve(string &s1,string &s2,int id1,int id2,vector<vector<int>>&dp){
        if(id1<0 || id2<0) return 0;
        if(dp[id1][id2]!=-1)  return dp[id1][id2];
        if(s1[id1]==s2[id2]) return 1+solve(s1,s2,id1-1,id2-1,dp);

        return dp[id1][id2]=max(solve(s1,s2,id1-1,id2,dp),solve(s1,s2,id1,id2-1,dp));
    }
    int solvetab(string &s1,string &s2,int id1,int id2,vector<vector<int>>&dp){
        for(int i=0;i<id1;i++){
            for(int j=0;j<id2;j++){
                if(s1[i]==s2[j]) {
                    if(i-1>=0 && j-1>=0)  dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=1;
                }
                else if(s1[i]!=s2[j]){
                    int left=0,right=0;
                    if(i-1>=0) left=dp[i-1][j];
                    if(j-1>=0) right=dp[i][j-1];
                    dp[i][j]=max(left,right);
                }
            }
        }
        return dp[id1-1][id2-1];
    }
    int space(string &s1,string &s2,int id1,int id2){
        vector<int>prev(id2,0);
      
         for(int i=0;i<id1;i++){
            vector<int>curr(id2,0);
            for(int j=0;j<id2;j++){
                if(s1[i]==s2[j]) {
                    if(i-1>=0 && j-1>=0)  curr[j]=1+prev[j-1];
                    else curr[j]=1;
                }
                else if(s1[i]!=s2[j]){
                    int left=0,right=0;
                    if(i-1>=0) left=prev[j];
                    if(j-1>=0) right=curr[j-1];
                    curr[j]=max(left,right);
                }
            }
            prev=curr;
        }
        return prev[id2-1];

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        //int ans=solvetab(text1,text2,n1,n2,dp);
        int ans=space(text1,text2,n1,n2);
        return ans;
    }
};