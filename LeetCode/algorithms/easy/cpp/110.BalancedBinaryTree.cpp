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
    bool answer = true;
    int order(TreeNode* node, bool& answer) {
        if(node == nullptr)
            return true;
        
        int left = (node->left == nullptr) ? 0 : order(node->left, answer);
        int right = (node->right == nullptr) ? 0 : order(node->right, answer);

        if (abs(left - right) > 1 && answer == true)
            answer = false;

        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        order(root, answer);

        return answer;
    }
};
