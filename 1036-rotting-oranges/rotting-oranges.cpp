class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int,int>>> q;
        int fresh = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Initialization
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        int maxTime = 0;

        while (!q.empty()) {
            auto [t, cell] = q.front();
            auto [row, col] = cell;
            q.pop();

            maxTime = max(maxTime, t);

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
                    q.push({t + 1, {nrow, ncol}});
                }
            }
        }

        return fresh == 0 ? maxTime : -1;
    }
};