class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& a, int node, int c, vector<int>& colors) {
        colors[node] = c;

        for (int i = 0; i < a[node].size(); i++) {
            int neighbour = a[node][i];

            if (colors[neighbour] != -1 && colors[neighbour] == c)
                res = false;

            if (colors[neighbour] == -1)
                dfs(a, neighbour, 1 - c, colors);
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n, -1);

        for(int i = 0; i < n; i++){
            if(colors[i] == -1)
              dfs(graph, i, 0, colors);
        }
        return res;
    }
};