class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<min(n,k);i++){
          pq.push({matrix[0][i],0,i});
        }
        while(k>0){
            vector<int>pair=pq.top();
             k--;
            if(k==0) return pair[0];
            
            int i=pair[1],j=pair[2];
            pq.pop();
            if(i+1<n) pq.push({matrix[i+1][j],i+1,j});
        }
        return -1;
    }
};