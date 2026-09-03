class Solution {
public:
    void fun(string& s, int n, int idx, string& diary, vector<string>& res,
             unordered_map<char, string>& mp) {

        if (idx == n) {
            res.push_back(diary);
            return;
        }

        string choice = mp[s[idx]];

        for (int j = 0; j < choice.size(); j++) {

            diary.push_back(choice[j]);

            fun(s, n, idx + 1, diary, res, mp);

            diary.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        int n = digits.size();

        vector<string> res;

        string diary = "";

        int idx = 0;

        fun(digits, n, idx, diary, res, mp);

        return res;
    }
};