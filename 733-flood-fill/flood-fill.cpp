class Solution {
public:
    void bfs(int sr,int sc, int color,int original_color,int n,int m,
    vector<vector<int>>& image,vector<vector<int>>& vis){
        image[sr][sc]=color;
        vis[sr][sc]=1;
        queue<pair<int,int>>q;
        q.push({sr,sc});

         int drow[]={-1,0,1,0};
         int dcol[]={0,-1,0,1};

        while(!q.empty()){

            int row=q.front().first;
            int col=q.front().second; q.pop();

            for(int i=0;i<4;i++){

               int new_row=row+drow[i];
               int new_col=col+dcol[i];
               
                if (new_row >= 0 && new_row < n &&
                new_col >= 0 && new_col < m &&
                image[new_row][new_col] == original_color &&
                vis[new_row][new_col] == 0) {
                q.push({new_row, new_col});
                vis[new_row][new_col] = 1;
                image[new_row][new_col]=color;
            }

            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int original_color=image[sr][sc];
        bfs(sr,sc,color,original_color,n,m,image,vis);
        return image;
    }
};