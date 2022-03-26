class Solution {
public:
    vector<int> answer;
    
    void travel(TreeNode* root) {
        if (root == nullptr)
            return;
        
        answer.push_back(root->val);
        travel(root->left);
        travel(root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        travel(root1);
        travel(root2);
        
        sort(answer.begin(), answer.end());
        return answer;
    }
};
