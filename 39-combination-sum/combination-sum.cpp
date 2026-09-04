class Solution {
public:
    void fun(vector<int>& candidates, int n, int idx, vector<int>& diary,
             int sum, vector<vector<int>>& result, int target) {

        if (idx == n) {
            if (sum == target) {
                result.push_back(diary);
            }
            return;
        }

        fun(candidates, n, idx + 1, diary, sum, result, target);

        if (sum + candidates[idx] <= target) {
            diary.push_back(candidates[idx]);
            sum += candidates[idx];

            fun(candidates, n, idx, diary, sum, result, target);

            diary.pop_back();
            sum -= candidates[idx];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        int sum = 0;

        vector<int> diary;

        vector<vector<int>> result;

        fun(candidates, n, 0, diary, sum, result, target);

        return result;
    }
};