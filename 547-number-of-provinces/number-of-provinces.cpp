class Solution {
public:
    void bfs(int i,vector<int>&vis,vector<vector<int>>adj){
       queue<int>q;
       q.push(i);
       while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(vis[it]!=1)
            q.push(it); vis[it]=1;
        }
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                   adj[i].push_back(j);
                  
                }
            }
        }
        vector<int>vis(n,0);int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++; bfs(i,vis,adj);
                vis[i]=1;
            }
        }
        return cnt;
    }
};