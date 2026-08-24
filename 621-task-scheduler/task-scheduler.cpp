class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {

        int size = tasks.size();

        unordered_map<char, int> freq;
        unordered_map<char, int> free;

        // Frequency count
        for (int i = 0; i < size; i++) {
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        // Max Heap
        // {frequency, task}
        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        int seat = 1;

        // Tasks which cannot be placed currently
        vector<pair<int, char>> corner;

        while (!pq.empty()) {

            corner.clear();

            // Try to fill current seat
            while (!pq.empty()) {

                pair<int, char> p = pq.top();
                pq.pop();

                int f = p.first;
                char task = p.second;

                // Can task be placed?
                if (free[task] <= seat) {

                    // Place task
                    f--;

                    // Task still remaining
                    if (f > 0) {
                        pq.push({f, task});
                    }

                    // Next free seat
                    free[task] = seat + n + 1;

                    break;
                }

                // Cannot place -> corner
                else {
                    corner.push_back({f, task});
                }
            }

            // Put corner tasks back
            for (auto p : corner) {
                pq.push(p);
            }

            seat++;
        }

        return seat - 1;
    }
};