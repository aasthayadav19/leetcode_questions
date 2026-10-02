class Solution {
public:
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};

    bool valid(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        int time = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty() && fresh > 0) {
            time++;

            int s = q.size();

            while (s--) {
                pair<int, int> p = q.front();
                q.pop();

                int currRow = p.first;
                int currCol = p.second;

                for (int k = 0; k < 4; k++) {
                    int newRow = currRow + x[k];
                    int newCol = currCol + y[k];

                    if (valid(newRow, newCol, n, m) && grid[newRow][newCol] == 1) {

                        q.push({newRow, newCol});

                        grid[newRow][newCol] = 2;
                        fresh--;
                    }
                }
            }
        }

        if (fresh > 0) {
            return -1;
        }

        return time;
    }
};