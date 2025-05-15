class Solution {
public:
    bool bfs(int i,vector<vector<int>>& graph,vector<int>&vis,vector<int>&color){
        queue<int>q;color[i]=0;
        q.push(i);
        while(!q.empty()){
            int node=q.front();q.pop();
            int flag=!color[node];
           for(auto it:graph[node]){
            if(vis[it]==0){
                vis[it]=1; color[it]=flag; q.push(it);
            }
            else if(color[it]!=flag) return false;
           }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>vis(n,0);
        vector<int>color(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0) {
                if(!bfs(i,graph,vis,color)) return false;
            }
        }
        return true;
    }
};