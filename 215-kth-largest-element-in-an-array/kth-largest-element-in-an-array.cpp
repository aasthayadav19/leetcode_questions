class Solution {
public:
#define nums a
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();

        int i;
        for (i = 0; i < k; i++) {
            pq.push(a[i]);
        }
        for (i = k; i < n; i++) {
            if (a[i] <= pq.top())
                continue;
            pq.pop();
            pq.push(a[i]);
        }

        return pq.top();
    }
};