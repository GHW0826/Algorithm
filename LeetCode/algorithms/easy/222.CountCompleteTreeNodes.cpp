class Solution {
public:
    int cnt = 0;

    void order(TreeNode* node) {
        ++cnt;
        if (node->left != nullptr)
            order(node->left);
        if (node->right != nullptr)
            order(node->right);
    }

    int countNodes(TreeNode* root) {
        if (root != nullptr)
            order(root);
        return cnt;
    }
};
