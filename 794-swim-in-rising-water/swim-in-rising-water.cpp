class Solution {
public:
    // binary search and bfs
    bool bfs(vector<vector<int>>& a, int n, int m, int money) {
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        if (a[0][0] > money)
            return false;

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            int row = p.first;
            int col = p.second;

            if (row == n - 1 && col == m - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int r = row + x[k];
                int c = col + y[k];

                if (r < 0 || r >= n || c < 0 || c >= m)
                    continue;

                if (vis[r][c])
                    continue;

                if (a[r][c] > money)
                    continue;

                q.push({r, c});
                vis[r][c] = 1;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int low = grid[0][0];
        int high = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                high = max(high, grid[i][j]);
            }
        }

        int res = high;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            if (bfs(grid, n, m, guess)) {
                res = guess;
                high = guess - 1;
            } else {
                low = guess + 1;
            }
        }

        return res;
    }
};