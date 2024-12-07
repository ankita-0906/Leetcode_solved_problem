class Solution {
public:
   int solve(vector<vector<int>>& arr,int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0 && arr[i][j]==0) return 1;
    else if(i<0 || j<0) return 0;
    else if(arr[i][j]==1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=solve(arr,i-1,j,dp);
    int down=solve(arr,i,j-1,dp);
    return dp[i][j]=up+down;
   }


    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size(); int n=arr[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int cnt=solve(arr,m-1,n-1,dp);
        return cnt;
    }
};