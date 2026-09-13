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
    bool fun(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
            return false;

        if (root1->val != root2->val)
            return false;

        bool r1 = fun(root1->left, root2->left);

        bool r2 = fun(root1->right, root2->right);

        if (r1 == true && r2 == true)
            return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) { return fun(p, q); }
};