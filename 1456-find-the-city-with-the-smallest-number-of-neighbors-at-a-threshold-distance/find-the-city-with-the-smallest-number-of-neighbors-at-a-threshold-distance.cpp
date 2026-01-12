class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int ansCity = -1;
        int minReach = INT_MAX;

        for (int src = 0; src < n; src++) {

            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u]) continue;

                for (auto [v, wt] : adj[u]) {
                    if (dist[v] > d + wt) {
                        dist[v] = d + wt;
                        pq.push({dist[v], v});
                    }
                }
            }

            int count = 0;
            for (int i = 0; i < n; i++) {
                if (i != src && dist[i] <= distanceThreshold)
                    count++;
            }

            if (count < minReach || (count == minReach && src > ansCity)) {
                minReach = count;
                ansCity = src;
            }
        }

        return ansCity;
    }
};