class Solution {
public:
  
   bool ispossible(int row,int col, vector<int>&queen){
     
     for(int i=0;i<row;i++){
        int prow=i; int pcol=queen[i];
     if(pcol==col || abs(prow-row)==abs(pcol-col)) return false;
     }
     return true;
   }
   int rec(int level,int  n,vector<int>&queen){
    if(level==n) return 1;
    if(level>n) return 0;
     
     int ans=0;
     for(int i=0;i<n;i++){
        if(ispossible(level,i,queen)){
         queen[level]=i;
        ans=ans+ rec(level+1,n,queen);
        queen[level]=-1;
        }
     }
     return ans;
   }
    int totalNQueens(int n) {
         vector<int>queen(n,-1);
        
        
        return rec(0,n,queen);
    }
};