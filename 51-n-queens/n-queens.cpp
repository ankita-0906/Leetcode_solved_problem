class Solution {
public:
  bool issafe(int row,int col,int n,vector<string> &board){

    //checking each column of the row

     for(int i=row-1;i>=0;i--){
      if(board[i][col]=='Q') return false;
     }

     //checking upper left diagonal

     for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q') return false;
     }

     //checking upper right diagonal
       for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q') return false;
     }
     return true;
  }
    void solve(int row,int n,vector<vector<string>>&ans,vector<string>&board){
        if(row==n){
         ans.push_back(board);
         return;
        }
        for(int i=0;i<n;i++){
            if(issafe(row,i,n,board)){
              board[row][i]='Q';
              solve(row+1,n,ans,board);
              board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
       
        solve(0,n,ans,board);
        return ans;
    }
};