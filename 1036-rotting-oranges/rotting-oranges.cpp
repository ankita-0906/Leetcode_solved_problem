class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Push all rotten oranges to queue and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        int time = 0;

        while (!q.empty()) {
            int sz = q.size();
            bool changed = false;
            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 1 &&
                        vis[nrow][ncol] == 0) {
                        
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                        fresh--;
                        q.push({nrow, ncol});
                        changed = true;
                    }
                }
            }
            if (changed) time++; // only increment if at least one orange rotted
        }

        return fresh == 0 ? time : -1;
    }
};
