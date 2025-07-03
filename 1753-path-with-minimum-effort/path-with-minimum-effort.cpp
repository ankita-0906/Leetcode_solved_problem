class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vis[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto [dist, coord] = pq.top();
            int row = coord.first, col = coord.second;
            pq.pop();
             int drow[]={-1,0,1,0};
             int dcol[]={0,-1,0,1};
            
             for(int i=0;i<4;i++){
                int newrow=row+drow[i];
                int newcol=col+dcol[i];
                
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<m){
                int newdist=max(dist,abs(heights[row][col]-heights[newrow][newcol]));
                if(newdist<vis[newrow][newcol]){
                    vis[newrow][newcol]=newdist;
                    pq.push({newdist,{newrow,newcol}});
                }
                }
             }
        }
        return vis[n-1][m-1];
    }
};