struct Node {
public:
    int val_;
    Node* left_;
    Node* right_;
    Node() : val_(0), left_(nullptr), right_(nullptr) {}
    Node(int val) : val_(val), left_(nullptr), right_(nullptr) {}
    Node(int val, Node* left, Node* right) : val_(val), left_(left), right_(right) {}
};

void preOrder(Node* node)
{
    cout << node->val_ << " ";
    if (node->left_ != nullptr)
        preOrder(node->left_);
    if (node->right_ != nullptr)
        preOrder(node->right_);
}

void inOrder(Node* node)
{
    if (node->left_ != nullptr)
        inOrder(node->left_);
    cout << node->val_ << " ";
    if (node->right_ != nullptr)
        inOrder(node->right_);
}

void postOrder(Node* node)
{
    if (node->left_ != nullptr)
        postOrder(node->left_);
    if (node->right_ != nullptr)
        postOrder(node->right_);
    cout << node->val_ << " ";
}

void levelOrder(Node* node)
{
    queue<Node*> q;
    q.push(node);

    while (q.empty() == false) {
        Node* node = q.front();
        q.pop();

        cout << node->val_ << " ";
        if (node->left_ != nullptr)
            q.push(node->left_);
        if (node->right_ != nullptr)
            q.push(node->right_);
    }
}
