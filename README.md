
- Binary Search


- two pointers


- permutation, Combination


- DFS
```cpp
std::vector<bool> visit;
vector<vector<int>> Graph;
 
void DFS(const std::vector<std::vector<int>>& Graphe, int Start, std::vector<bool>& Visited)
{
	std::cout << Start << " ";
	Visited[Start] = true;

	for (int i = 0; i < Graphe[Start].size(); ++i) {
		if (Visited[Graph[Start][i]] == false)
			DFS(Graphe, Graph[Start][i], Visited);
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

	while (!q.empty()) {
		int front = BFSQ.front();
		q.pop();

		if (Visited[front] == false) {
			std::cout << front << " ";
			Visited[front] = true;
		}

		for (int i = 0; i < Graph[front].size(); ++i) {
			if (Visited[Graph[front][i]] == false)
				q.push(Graph[front][i]);
		}
	}

}
```
