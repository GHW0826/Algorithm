
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return { };
        
        vector<vector<int>> answer;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        while (q.empty() == false) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (answer.size() <= depth)
                answer.push_back(vector<int>());
            
            answer[depth].push_back(node->val);
            
            if (node->left != nullptr)
                q.push(make_pair(node->left, depth + 1));
            if (node->right != nullptr)
                q.push(make_pair(node->right, depth + 1));
        }
        
        return answer;
    }
};
