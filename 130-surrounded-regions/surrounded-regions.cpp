class Solution {
public:
     void bfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis,
  vector<vector<char>>&ans){
      int n=grid.size(),m=grid[0].size();
      queue<pair<int,int>>q;
      q.push({i,j});
      vis[i][j]=1;ans[i][j]='O';
      
      int dr[]={0,-1,0,1};  int dc[]={-1,0,1,0};
      
      while(!q.empty()){
          int row=q.front().first, col=q.front().second; q.pop();
          
          for(int k=0;k<4;k++){
             int nr=row+dr[k], nc=col+dc[k];
             
             if(nr>=0 && nr<n && nc>=0 && nc<m &&
             vis[nr][nc]==0 && grid[nr][nc]=='O'){
                 
                 vis[nr][nc]=1; q.push({nr,nc}); ans[nr][nc]='O';
             }
          }
      }
  }
    void solve(vector<vector<char>>& grid) {
         int n=grid.size(),m=grid[0].size();
        vector<vector<char>>ans(n,vector<char>(m,'X'));
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        //1st row
        
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O') bfs(i,0,grid,vis,ans);
        }
        
        //last row
        for(int i=0;i<n;i++){
            if(grid[i][m-1]=='O') bfs(i,m-1,grid,vis,ans);
        }
        
        //1st col
        for(int j=0;j<m;j++){
            if(grid[0][j]=='O') bfs(0,j,grid,vis,ans);
        }
        //last col
        for(int j=0;j<m;j++){
            if(grid[n-1][j]=='O') bfs(n-1,j,grid,vis,ans);
        }
        grid=ans;
    }
};