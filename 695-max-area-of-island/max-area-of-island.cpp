class Solution {
public:
int bfs(vector<vector<int>>&vis, vector<vector<int>>&grid,int i,int j){
    int m=grid.size(),n=grid[0].size();
    int cnt=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    int drow[]={-1,0,1,0};
    int dcol[]={0,-1,0,1};
    while(!q.empty()){
        auto[row,col]=q.front();
        q.pop();
      for(int i=0;i<4;i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n &&
         grid[nrow][ncol]==1 && vis[nrow][ncol]==-1){
            vis[nrow][ncol]=1;
            q.push({nrow,ncol});
           cnt++;
         }
      }
    }
    return cnt;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        int maxi=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==-1 && grid[i][j]==1){
                    vis[i][j]=1;
                   maxi=max(maxi,bfs(vis,grid,i,j));
                }
            }
        }
        return maxi;
    }
};