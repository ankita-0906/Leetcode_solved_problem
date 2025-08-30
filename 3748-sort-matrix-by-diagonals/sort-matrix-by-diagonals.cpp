class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
             mp[i-j].push_back(grid[i][j]);
             }
        }
             for(auto &it:mp){
                if(it.first>=0) 
                sort(it.second.begin(),it.second.end(),greater<int>());
                else 
                sort(it.second.begin(),it.second.end());
             }
             unordered_map<int,queue<int>>pq;
             for(auto it:mp){
                queue<int>q;
                for(auto val:it.second)
                q.push(val);

                pq[it.first]=q;
             }

             for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    grid[i][j]=pq[i-j].front();
                    pq[i-j].pop();
                }
             }
             
        
        return grid;
    }
};