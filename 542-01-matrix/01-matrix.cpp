class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    
                 vis[i][j]=1; ans[i][j]=0;
                q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second; q.pop();
           
            
            int drow[]={-1,0,1,0};
            int dcol[]={0,-1,0,1};
            
            for(int k=0;k<4;k++){
                int nrow=i+drow[k]; int ncol=j+dcol[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1
                && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;ans[nrow][ncol]=dis+1;
                    q.push({{nrow,ncol},dis+1});
                }
            }
            
        }
        return ans;
    }
};