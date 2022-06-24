class Solution {
public:
    int depth_ = 0;
    
    void order(TreeNode* node, int depth) {
        
        depth_ = max(depth, depth_);
        if (node->left != nullptr)
            order(node->left, depth + 1);
        if (node->right != nullptr)
            order(node->right, depth + 1);
    }
    
    int maxDepth(TreeNode* root) {
        if (root != nullptr)
            order(root, 1);
        return depth_;
    }
};
