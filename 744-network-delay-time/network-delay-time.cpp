class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i=0;i<times.size();i++){
            int start=times[i][0],end=times[i][1],time=times[i][2];
            adj[start].push_back({end,time});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,k});
         vector<int>vis(n+1,INT_MAX); vis[k]=0;

        while(!pq.empty()){
           
           auto[time,node]=pq.top();
            pq.pop();
           

            for(auto it:adj[node]){
                int newtime=time+it.second;
                if(newtime<vis[it.first]){
                    vis[it.first]=newtime;
                    pq.push({newtime,it.first});
                }
            }
        }
            
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,vis[i]);
        }
        if(maxi==INT_MAX) return -1;
        return maxi;
    }
};