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

    bool isSameSubTree(TreeNode* node, TreeNode* subRoot) {
        if (node == nullptr && subRoot == nullptr)
            return true;
        else if (node != nullptr && subRoot != nullptr) {
            bool answer = (node->val == subRoot->val);
            answer &= isSameSubTree(node->left, subRoot->left);
            answer &= isSameSubTree(node->right, subRoot->right);
            return answer;
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        else if (subRoot == nullptr)
            return true;

        if (isSameSubTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
