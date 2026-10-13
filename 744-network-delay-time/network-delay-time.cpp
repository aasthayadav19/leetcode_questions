class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          vector<vector<pair<int, int>>> a(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            a[u].push_back({v, w});
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            if (d > dist[node])
                continue;

            for (int j = 0; j < a[node].size(); j++) {
                int neigh = a[node][j].first;
                int wt = a[node][j].second;

                if (d + wt < dist[neigh]) {
                    dist[neigh] = d + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};