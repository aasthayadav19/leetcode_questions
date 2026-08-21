class Solution {
public:

    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> f;

        // Frequency count
        for (int i = 0; i < nums.size(); i++) {
            f[nums[i]]++;
        }

        // Min heap: {frequency, element}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            cmp
        > pq;

        // Process each unique element
        for (auto i : f) {

            int element = i.first;
            int freq = i.second;

            pair<int, int> curr = {freq, element};

            if (pq.size() < k) {
                pq.push(curr);
            }
            else if (curr.first > pq.top().first) {
                pq.pop();
                pq.push(curr);
            }
        }

        // Store answer
        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};