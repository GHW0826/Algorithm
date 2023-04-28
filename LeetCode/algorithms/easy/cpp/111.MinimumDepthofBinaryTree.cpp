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
    int answer = 987654321;

    void order(TreeNode* node, int depth) {
        if (node->left != nullptr)
            order(node->left, depth + 1);
        if (node->right != nullptr)
            order(node->right, depth + 1);
        if (node->left == nullptr && node->right == nullptr) {
            if (depth < answer)
                answer = depth;
        }
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        order(root, 1);
        return answer;
    }
};
