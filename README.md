
- Binary Search


- two pointers


- permutation, Combination


- DFS
```cpp
std::vector<bool> visit;
vector<vector<int>> Graph;
 
void DFS(const std::vector<std::vector<int>>& Graphe, int Start, std::vector<bool>& Visited)
{
	int DepthSize = Graphe[Start].size();
	std::cout << Start << " ";
	Visited[Start] = true;

	for (int i = 0; i < DepthSize; ++i) {
		if (Visited[Graphe[Start][i]] == false)
			DFS(Graphe, Graphe[Start][i], Visited);
	}
}
```

- BFS
```cpp
std::vector<bool> visit;
vector<vector<int>> Graph;

void BFS(const std::vector<std::vector<int>>& Graph, int Start, std::vector<bool>& Visited)
{
	std::queue<int> q;

	q.push(Start);

	while (!BFSQ.empty()) {
		int front = BFSQ.front();
		q.pop();

		if (Visited[front] == false) {
			std::cout << front << " ";
			Visited[front] = true;
		}

		int LevelSize = Graphe[front].size();
		for (int i = 0; i < LevelSize; ++i) {
			if (Visited[Graphe[front][i]] == false)
				q.push(Graphe[front][i]);
		}
	}

}
```
