class Solution {
public:
   bool dfs(int i,int j,string word,vector<vector<char>>& board,int index,
   vector<vector<int>>&vis,int n,int m){
    
        if(index>=word.size()) return true;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        for(int k=0;k<4;k++){
            int nc=j+dr[k];
            int nr=i+dc[k];
            if(nc>=0 && nr>=0 && nc<m && nr<n && vis[nr][nc]==0 &&
             board[nr][nc]==word[index] ){
                vis[nr][nc]=1;
                if(dfs(nr,nc,word,board,index+1,vis,n,m)) return true;
                vis[nr][nc]=0;
             }
        }
        return false;
   }
    bool exist(vector<vector<char>>& board, string word) {
       
        int n=board.size();
        int m=board[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(board[i][j]==word[0]) {
                vis[i][j]=1;
                if(dfs(i,j,word,board,1,vis,n,m)) return true;;
                vis[i][j]=0;
               }
            }
        }
        return false;
    }
};