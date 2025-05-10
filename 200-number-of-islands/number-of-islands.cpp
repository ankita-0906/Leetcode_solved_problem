class Solution {
public:
    void solve(int new_row,int new_col,vector<vector<char>>& grid,vector<vector<int>>&vis,
                int n,int m,queue<pair<int,int>>&q){
      if(new_row>=0 && new_row<n && 
                  new_col>=0 && new_col<m && 
                  grid[new_row][new_col]=='1' && vis[new_row][new_col]==0){

                q.push({new_row,new_col});vis[new_row][new_col]=1;
                }
    }
    void bfs(int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
           int row=q.front().first;
           int col=q.front().second;
           q.pop();int new_row,new_col;
            // up
             new_row=row-1, new_col=col;
             solve(new_row,new_col,grid,vis,n,m,q);
            //down
            new_row=row+1, new_col=col;
            solve(new_row,new_col,grid,vis,n,m,q);
            //left
            new_row=row, new_col=col-1;
            solve(new_row,new_col,grid,vis,n,m,q);
            //right
            new_row=row, new_col=col+1;
            solve(new_row,new_col,grid,vis,n,m,q);
            
           
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             if(vis[i][j]==0 && grid[i][j]=='1'){
              bfs(i,j,n,m,vis,grid);
             cnt++;
             }
            }
        }
        return cnt;
    }
};