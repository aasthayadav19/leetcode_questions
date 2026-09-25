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

    vector<TreeNode*> nodes;
    vector<int> res;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        nodes.push_back(root);
        res.push_back(root->val);

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        int gcount = 0;

        int g1first , g1second, g2first , g2second ;

        for (int i = 0; i < res.size() - 1; i++) {

            if (res[i] > res[i + 1]) {

                if (gcount == 0) {
                    g1first = i;
                    g1second = i + 1;
                }
                else {
                    g2first = i;
                    g2second = i + 1;
                }

                gcount++;
            }
        }

        if (gcount == 1) {
            swap(nodes[g1first]->val,
                 nodes[g1second]->val);
        }

        else if (gcount == 2) {
            swap(nodes[g1first]->val,
                 nodes[g2second]->val);
        }
    }
};