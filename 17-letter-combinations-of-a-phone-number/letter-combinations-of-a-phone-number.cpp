class Solution {
public:
    void fun(string& digits, int n, int idx, string& diary,
             vector<string>& res) {

        // Base Case
        if (idx == n) {
            res.push_back(diary);
            return;
        }

        // Digit ki corresponding letters
        vector<string> mp = {"",    "",    "abc",  "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string choice = mp[digits[idx] - '0'];

        // Saare choices try karo
        for (int j = 0; j < choice.size(); j++) {

            diary.push_back(choice[j]);

            fun(digits, n, idx + 1, diary, res);

            diary.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.empty())
            return res;

        string diary = "";

        fun(digits, digits.size(), 0, diary, res);

        return res;
    }
};