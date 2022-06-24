class Solution {
public:
    vector<int> answer;
    
    void preorder(TreeNode* root) {
        answer.push_back(root->val);
        
        if (root->left != nullptr)
            preorder(root->left);
        if (root->right != nullptr)
            preorder(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        if (root != nullptr)
            preorder(root);
        return answer;
    }
};
