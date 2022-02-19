
- Binary Search


- two pointers


- permutation, Combination


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
