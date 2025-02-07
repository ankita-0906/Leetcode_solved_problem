class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>row,col;
       unordered_map<int,pair<int,int>>hash;

        int len=arr.size();
        int n=mat.size(),m=mat[0].size();

       for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
           hash[mat[i][j]]={i,j};
           }
        }
        
        for(int i=0;i<len;i++){
           auto num=hash[arr[i]];
            row[num.first]++;  col[num.second]++;
            if(row[num.first]==m || col[num.second]==n ) return i;
        }
        return n-1;
    }
};