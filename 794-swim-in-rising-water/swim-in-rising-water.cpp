class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(
            n, vector<int>(n, INT_MAX)
        );

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int water = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if (water > dist[r][c])
                continue;

            if (r == n - 1 && c == n - 1)
                return water;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= n)
                    continue;

                int newWater = max(
                    water, grid[nr][nc]
                );

                if (newWater < dist[nr][nc]) {
                    dist[nr][nc] = newWater;
                    pq.push({newWater, {nr, nc}});
                }
            }
        }

        return -1;
    }
};
