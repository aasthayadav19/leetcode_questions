class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int src = k;
        src--;
        // create adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<times.size(); i++){
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            adj[s-1].push_back({d-1,w});
        }
        // create min heap of pairs
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            if(d > dist[node])
                continue;
            
            // check for the neigh
            for(int j=0; j<adj[node].size(); j++){
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;

                if(d + wt < dist[neigh]){
                    dist[neigh] = d + wt;
                    pq.push({d + wt, neigh});
                }
            }
        }
        int res=0;
        for(int i=0; i<n; i++){
            res = max(res,dist[i]);
        }
        if(res != INT_MAX)
            return res;
        return -1;
    }
};