
- Binary Search

- Recursion


- DP(Dynamic programming)


- two pointers


- permutation, Combination
  - permutation (정렬된 상태에서 가능)
```cpp
    vector<int> arr;	// 주어진 arr
    vector<int> perm;	// per 만드는 진행중 보관할 컨테이너
    vector<bool> visit;	// 
    int r;		// nPr;
    void permutation()
    {
    	if (answer.size() == r)
	    return;
	for (int i = 0; i < arr.size(); ++i) {
	    if (visit[i] == false) {
	    	visit[i] = true;
		perm.push_back(arr[i]);
		permutation();
		perm.pop_back();
		visit[i] = false;
	    }
	}
    }
```

- DFS
```cpp
// Graph에 연결 노드 번호가 들어있음.
std::vector<bool> visit;
vector<vector<int>> Graph;
 
void DFS(int Start)
{
	std::cout << Start << " ";
	visit[Start] = true;

	for (int i = 0; i < Graphe[Start].size(); ++i) {
		if (visit[Graph[Start][i]] == false)
			DFS(Graph[Start][i]);
	}
}
```

- BFS
```cpp
// Graph에 연결 노드 번호가 들어있음.
std::vector<bool> visit;
vector<vector<int>> Graph;

void BFS(int Start)
{
	std::queue<int> q;
	q.push(Start);

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		if (visit[front] == false) {
			std::cout << front << " ";
			visit[front] = true;
		}

		for (int i = 0; i < Graph[front].size(); ++i) {
			if (visit[Graph[front][i]] == false)
				q.push(Graph[front][i]);
		}
	}

}
```

- Backtracking
