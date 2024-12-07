class Solution {
public:
//----------------------memorisation---------------------------------------
   int solve(vector<vector<int>>& arr,int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0 && arr[i][j]==0) return 1;
    else if(i<0 || j<0) return 0;
    else if(arr[i][j]==1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=solve(arr,i-1,j,dp);
    int down=solve(arr,i,j-1,dp);
    return dp[i][j]=up+down;
   }

//---------------------------tabulation--------------------------------------
int tabsolve(vector<vector<int>>& arr,int m,int n,vector<vector<int>>&dp){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0 && arr[i][j]==0) {
                dp[i][j]=1; continue;
            }
           else if(arr[i][j]==1){
               dp[i][j]=0; continue;
           } 
           int left=0,up=0;
           if(i>0) up=dp[i-1][j];
           if(j>0) left=dp[i][j-1];
           dp[i][j]=left+up;
        }
    }
    return dp[m-1][n-1];
}
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size(); int n=arr[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //int cnt=solve(arr,m-1,n-1,dp);
        int cnt=tabsolve(arr,m,n,dp);
        return cnt;
    }
};