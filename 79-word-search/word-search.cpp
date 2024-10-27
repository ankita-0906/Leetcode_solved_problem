class Solution {
public:

int solve(vector<vector<char>>& board,int row,int col,string word,int index,int t_row,int t_col){
    //base case
    if(index==word.length()) return 1;
    if(row<0 || row >=t_row || col<0 || col>=t_col || board[row][col]!=word[index] ||
      board[row][col]=='&')
      return 0;

     char temp=board[row][col];
     board[row][col]='&';

     //checking upper letter
    int ans= solve(board,row-1,col,word,index+1,t_row,t_col) || 
             solve(board,row+1,col,word,index+1,t_row,t_col)||
             solve(board,row,col-1,word,index+1,t_row,t_col) ||
             solve(board,row,col+1,word,index+1,t_row,t_col);
       
       board[row][col]=temp;
       return ans;
      }
    

    bool exist(vector<vector<char>>& board, string word) {
        int n=word.length(),ans;
        int t_row=board.size();
        int t_col=board[0].size();
        for(int i=0;i<t_row;i++){
            for(int j=0;j<t_col;j++){
                
                 ans=solve(board,i,j,word,0,t_row,t_col);
                 if(ans) return true;
            }
        }
        return false;
    }
};