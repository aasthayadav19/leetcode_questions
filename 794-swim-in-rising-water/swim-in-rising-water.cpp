
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

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int water = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if (water > dist[row][col])
                continue;

            if (row == n - 1 && col == n - 1)
                return water;

            for (int k = 0; k < 4; k++) {
                int r = row + dx[k];
                int c = col + dy[k];

                if (r < 0 || r >= n ||
                    c < 0 || c >= n)
                    continue;

                int newWater = max(water, grid[r][c]);

                if (newWater < dist[r][c]) {
                    dist[r][c] = newWater;
                    pq.push({newWater, {r, c}});
                }
            }
        }

        return -1;
    }
};
