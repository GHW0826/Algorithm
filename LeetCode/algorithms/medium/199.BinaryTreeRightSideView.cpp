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
    vector<int> path_;
    void order(TreeNode* node, int depth) {
        if (path_.size() == depth)
            path_.push_back(node->val);

        if (node->right != nullptr)
            order(node->right, depth + 1);
        if (node->left != nullptr)
            order(node->left, depth + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return {};
        order(root, 0);
        return path_;
    }
};
