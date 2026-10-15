
class Solution {
public:
    bool canReach(vector<vector<int>>& grid, int water) {
        int n = grid.size();

        if (grid[0][0] > water)
            return false;

        vector<vector<bool>> visited(
            n, vector<bool>(n, false)
        );

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= n)
                    continue;

                if (visited[nr][nc])
                    continue;

                if (grid[nr][nc] > water)
                    continue;

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int low = grid[0][0];
        int high = n * n - 1;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canReach(grid, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
