class Solution {
public:
   
   void bfs(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    vis[i][j] = 1;
    queue<pair<int,int>> q;
    q.push({i, j});
    
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int new_row = row + drow[k];
            int new_col = col + dcol[k];

            if (new_row >= 0 && new_row < n &&
                new_col >= 0 && new_col < m &&
                grid[new_row][new_col] == '1' &&
                vis[new_row][new_col] == 0) {
                q.push({new_row, new_col});
                vis[new_row][new_col] = 1;
            }
        }
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