class Solution {
public:
//-------------------------memorisation----------------------------------------
int solve(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0) return 1;
     if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int up=solve(i-1,j,dp);
    int left=solve(i,j-1,dp);

    return dp[i][j]=up+left;
}
//--------------------tabulation-------------------------------------------
  int solvetab(int m,int n,vector<vector<int>>&dp){
    dp[0][0]=1; int up,left;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) continue;
            up=0; left=0;
            if(i>0) up=dp[i-1][j];
            if(j>0)  left=dp[i][j-1];
             dp[i][j]=up+left;
        }
    }
    return dp[m-1][n-1];
  }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //int cnt=solve(m-1,n-1,dp);
         int cnt=solvetab(m,n,dp);
        return cnt;
    }
};