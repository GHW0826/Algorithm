## Tree


```cpp
  class Node
  {
    public:
      int val;
      Node* left;
      Node* right;
  }
  
  // left = index * 2 + 1;
  // right = index * 2 + 2;
  vector<int> binary_tree;
```

  - InOrder
```cpp
  void InOrder(Node* node) 
  {
    if (node == nullptr)
      return;
    
    InOrder(node->left);
    DoSomething()...;
    InOrder(node->right);
  }
```
  - PreOrder
```cpp
  void PreOrder(Node* node) 
  {
    if (node == nullptr)
      return;
    
    DoSomething()...;
    PreOrder(node->left);
    PreOrder(node->right);
  }
```
  - PostOrder
```cpp
  void PostOrder(Node* node) 
  {
    if (node == nullptr)
      return;
    
    PostOrder(node->left);
    PostOrder(node->right);
    DoSomething()...;
  }
```

  - LevelOrder
```cpp
  void LevelOrder(Node* root)
  {
    queue<Node*> q;
    q.push(root);
    
    while (q.empty() == false) {
      Node* node = q.front();
      q.pop();
      DoSomething()...;
      
      if (node->left != nullptr)
        q.push(node->left);
      if (node->right != nullptr)
        q.push(node->right);
    }
  }
```
