class Solution {
public:
   int solve(vector<vector<int>>& arr,int i,int j,vector<vector<int>>& dp){
    if(i==0 && j==0) return arr[0][0];
    if(i<0 || j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
     int up=solve(arr,i-1,j,dp);
     int left=solve(arr,i,j-1,dp);
     return dp[i][j]=arr[i][j]+min(left,up);
   }
   int solvetabs(vector<vector<int>>& arr,int m,int n){
    vector<int>prev(n,0);prev[0]=arr[0][0];
    int up,left;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) continue;
            up=INT_MAX; left=INT_MAX;
            if(i>0) up=prev[j];
            if(j>0)  left=prev[j-1];
             prev[j]=arr[i][j]+min(up,left);
        }
    }
    return prev[n-1];
  }

    int minPathSum(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //int cnt=solve(arr,m-1,n-1,dp);
         int cnt=solvetabs(arr,m,n);
        return cnt;
    }
};