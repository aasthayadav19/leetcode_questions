/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;

    void fun(TreeNode* root, int sum, vector<int>& diary, int target) {

        if (root == NULL)
            return;

        sum = sum + root->val;

        diary.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {

            if (sum == target) {
                res.push_back(diary);
            }

            diary.pop_back();

            return;
        }

        fun(root->left, sum, diary, target);

        fun(root->right, sum, diary, target);

        diary.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> diary;

        fun(root, 0, diary, targetSum);

        return res;
    }
};