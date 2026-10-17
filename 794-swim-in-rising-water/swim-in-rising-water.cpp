class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> res(n, vector<int>(m, 1e8));
        
        res[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        
        

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            pair<int, pair<int, int>>p = pq.top();
            pq.pop();

            int water = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if (water > res[row][col])
                continue;

            if (row == n - 1 && col == m - 1)
                return water;

            for (int k = 0; k < 4; k++) {
                int r = row + x[k];
                int c = col + y[k];

                if (r < 0 || r >= n ||
                    c < 0 || c >= m)
                    continue;

                int newWater = max(water, grid[r][c]);

                if (newWater < res[r][c]) {
                    res[r][c] = newWater;
                    pq.push({newWater, {r, c}});
                }
            }
        }

        return res[n-1] [m-1];
    }
};