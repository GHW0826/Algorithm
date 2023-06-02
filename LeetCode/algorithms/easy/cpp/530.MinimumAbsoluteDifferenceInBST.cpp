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
    vector<int> num;

    void order(TreeNode* node) {

        num.push_back(node->val);
        if (node->left != nullptr)
            order(node->left);
        if (node->right != nullptr)
            order(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        if (root != nullptr)
            order(root);

        int answer = 100000;
        sort(num.begin(), num.end());
        for (int i = 1; i < num.size(); ++i)
            answer = min(answer, num[i] - num[i - 1]);
        
        return answer;
    }
};
