class Solution {
public:
  bool ispossible(int row,int col,vector<string>&board,int n){
    // col chceking 
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q') return false;
    }
    //left diagonal 
   for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
    if(board[i][j]=='Q') return false;
   }
    //right diagonal 
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    if(board[i][j]=='Q') return false;
    return true;
  }
    void rec(int level, vector<vector<string>>&ans,vector<string>&board,int n){
        if(level==n) {
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
           if(ispossible(level,i,board,n)){
            board[level][i]='Q';
            rec(level+1,ans,board,n);
             board[level][i]='.';
           }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        rec(0,ans,board,n);
        return ans;
    }
};