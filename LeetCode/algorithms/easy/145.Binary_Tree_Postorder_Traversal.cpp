class Solution {
public:
    vector<int> answer;
    
    void postorder(TreeNode* root) {
        
        if (root->left != nullptr)
            postorder(root->left);
        if (root->right != nullptr)
            postorder(root->right);
        
        answer.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        if (root != nullptr)
            postorder(root);
        return answer;
    }
};
