class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
         int u=roads[i][0],v=roads[i][1], time=roads[i][2];
         adj[u].push_back({v,time});
         adj[v].push_back({u,time});
        }
         priority_queue<pair<long long,long long>, vector<pair<long long,long long>>,
        greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        vector<long long>vis(n, LLONG_MAX);
  vector<long long>freq(n,0);
        vis[0]=0; freq[0]=1;
        const int MOD = 1e9 + 7;
        while(!pq.empty()){
            auto[time,node]=pq.top();
            pq.pop();
            for(auto it:adj[node]){
                long long newtime=time+it.second;
                if(vis[it.first]>newtime){
                    vis[it.first]=newtime;
                    freq[it.first]=freq[node]%MOD;
                    pq.push({newtime,it.first});
                }
                else if(vis[it.first]==newtime){
                    freq[it.first]=(freq[node]+freq[it.first])%MOD;
                }
            }
        }
        return freq[n-1]%MOD;
    }
};