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
--------------------------------------------------------------------------------
- 이진 탐색 트리 (BST)
```
  이진 트리로 왼쪽노드는 부모노드 보다 작은 값, 오른쪽 노드는 부모노드 보다 큰 값으로 위치됨.
  
  삽입 : 왼쪽 or 오른쪽 노드에서 자식이 없는 leaf노드에 도달하면 왼쪽 or 오른쪽 노드에 추가됨
  삭제 : 삭제 노드의 자식이 0, 1, 2개 일때 방법이 다르다.
    0개  : 부모와 연결을 끊고 삭제해주면 됨.
    1개  : 삭제 노드의 부모 노드에 자식노드 연결.
    2개  : 오른쪽 서브트리 중 최소값노드를 삭제할 노드의 위치로 옮김.    
```
- BST (Make)
- BST (insert)
- BST (delete)
- BST (search)
- BST (invert)

--------------------------------------------------------------------------------
- B-Tree
- B+Tree
- Trie
