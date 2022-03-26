class Solution {
public:
    void inorder(vector<int>& v, TreeNode* node)
    {
        if (node == nullptr)
            return;
        
        inorder(v, node->left);
        v.push_back(node->val);
        inorder(v, node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        inorder(answer, root);
        
        return answer;
    }
};
