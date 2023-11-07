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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr)
            return {};

        queue<TreeNode*> q;        
        vector<double> answer;
        q.push(root);
        while (q.empty() == false) {
            double acc = 0;
            double levelCnt = q.size();
            for (int i = 0; i < levelCnt; ++i) {
                auto node = q.front();
                q.pop();
                acc += node->val;
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            answer.push_back(acc/ levelCnt);
        }
        return answer;
    }
};
