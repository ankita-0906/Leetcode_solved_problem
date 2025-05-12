class Solution {
public:

    void bfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
      int n=grid.size(),m=grid[0].size();
      queue<pair<int,int>>q;
      q.push({i,j});
      vis[i][j]=1;
      
      int dr[]={0,-1,0,1};  int dc[]={-1,0,1,0};
      
      while(!q.empty()){
          int row=q.front().first, col=q.front().second; q.pop();
          
          for(int k=0;k<4;k++){
             int nr=row+dr[k], nc=col+dc[k];
             
             if(nr>=0 && nr<n && nc>=0 && nc<m &&
             vis[nr][nc]==0 && grid[nr][nc]==1){
                 
                 vis[nr][nc]=1; q.push({nr,nc}); 
             }
          }
      }
  }

    int numEnclaves(vector<vector<int>>& grid) {
         int n=grid.size(),m=grid[0].size();
       
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        //1st row
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]==0) bfs(i,0,grid,vis);
        }
        
        //last row
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 && vis[i][m-1]==0) bfs(i,m-1,grid,vis);
        }
        
        //1st col
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && vis[0][j]==0) bfs(0,j,grid,vis);
        }
        //last col
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==1 && vis[n-1][j]==0) bfs(n-1,j,grid,vis);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};