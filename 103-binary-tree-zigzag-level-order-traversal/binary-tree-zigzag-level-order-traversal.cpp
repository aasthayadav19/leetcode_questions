/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        queue<TreeNode*> q;

        q.push(root);

        bool leftToRight = 1;

        while (!q.empty()) {

            int levelSize = q.size();

            vector<int> tmp(levelSize);

            int first = 0;
            int last = levelSize - 1;

            while (levelSize--) {

                TreeNode* t = q.front();
                q.pop();

                if (leftToRight) {
                    tmp[first] = t->val;
                    first++;
                }
                else {
                    tmp[last] = t->val;
                    last--;
                }

                if (t->left != NULL)
                    q.push(t->left);

                if (t->right != NULL)
                    q.push(t->right);
            }

            res.push_back(tmp);

            leftToRight = 1 - leftToRight;
        }

        return res;
    }
};