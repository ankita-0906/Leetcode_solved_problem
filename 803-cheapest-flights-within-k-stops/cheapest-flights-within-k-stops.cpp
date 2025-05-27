class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int start=flights[i][0],end=flights[i][1],price=flights[i][2];
            adj[start].push_back({end,price});
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        vector<int>vis(n,INT_MAX); k=k+2;  vis[src]=0;
        pq.push({1,{0,src}});
        while(!pq.empty()){
            int step=pq.top().first;
            int price=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();
           

            for(auto it:adj[node]){
                if(step+1<=k){
                if(vis[it.first]>it.second+price){
                    vis[it.first]=it.second+price;
                pq.push({step+1,{it.second+price,it.first}});
                }
                }
            }
        }
        if(vis[dst]==INT_MAX) return -1;
        return vis[dst];
    }
};