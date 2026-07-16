class Solution {
public:
    void bfs(queue<int>&pq,int i,vector<int>&vis,int n,vector<vector<int>>adj){
        while(!pq.empty()){
            int node=pq.front(); pq.pop();
            for(auto it:adj[node]){
                if(vis[it]==0){
                     pq.push(it);
                     vis[it]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n =arr[0].size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && arr[i][j]==1) adj[i].push_back(j);
            }
        }

        vector<int>vis(n,0); queue<int>pq;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                pq.push(i);
                vis[i]=1;
                cnt++;
                bfs(pq,i,vis,n,adj);
            }
        }
        return cnt;
    }
};