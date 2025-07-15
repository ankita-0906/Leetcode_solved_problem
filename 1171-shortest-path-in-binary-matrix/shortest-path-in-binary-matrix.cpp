class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>>vis(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({1,{0,0}}); vis[0][0]=1;
        
        while(!pq.empty()){
            auto[len,index]=pq.top();
            int row=index.first;
            int col=index.second;
            pq.pop();
           // if(row==n-1 && col==n-1) return vis[row][col];
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int newrow=row+i;
                    int newcol=col+j;
                    if(newrow>=0 && newcol>=0 && newrow<n && newcol<n && grid[newrow][newcol]==0){
                        int length=len+1;
                        if(length<vis[newrow][newcol]){
                            vis[newrow][newcol]=length;
                            pq.push({length,{newrow,newcol}});
                        }
                    }
                }
            }
        }
        if(vis[n-1][n-1]==INT_MAX) return -1;
        return vis[n-1][n-1];
    }
};