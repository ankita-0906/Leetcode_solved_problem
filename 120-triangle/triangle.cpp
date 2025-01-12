class Solution {
public:
    int solve(vector<vector<int>>&arr,int i,int j,vector<vector<int>>& dp,int n){
       if(i==n-1) return arr[i][j];
       if(dp[i][j]!=-1) return dp[i][j];
       int down=solve(arr,i+1,j,dp,n);
       int dia=solve(arr,i+1,j+1,dp,n);

       return dp[i][j]=arr[i][j]+min(down,dia);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(triangle,0,0,dp,n);
    }
};