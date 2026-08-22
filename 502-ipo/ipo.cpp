class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();

        // {capital, profit}
        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort according to capital
        sort(projects.begin(), projects.end());

        // Max Heap -> maximum profit
        priority_queue<int> pq;

        int idx = 0;

        // We can select at most k projects
        while (k--) {

            // Add all projects which we can currently afford
            while (idx < n && projects[idx].first <= w) {
                pq.push(projects[idx].second);
                idx++;
            }

            // No project is possible
            if (pq.empty()) {
                break;
            }

            // Choose project with maximum profit
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};