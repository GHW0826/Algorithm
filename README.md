
- Binary Search

- Recursion


- DP(Dynamic programming)


- two pointers

- 세그먼트 트리
```
  배열에서 특정 구간의 합을 빠르게 구할수 있음.
  트리 특성상 합을 구할때 시간 복잡도 O(logN)
  데이터 범위를 반씩 분할하여 그 구간의 합을 루트 노드에 저장.
  데이터의 개수 N에 4를 곱한 크기만큼 미리 구간 합 트리의 공간 할당.
  초기화, 배열의 원소 변경시 구간합 변경 업데이트, 구간 합 구하는 함수등을 구현하면됨.
```
- 펜웍 

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
- KMP 문자열 탐색
- Dijkstra 
- Bellman-Ford-Moore
- Floyd-Warshall 
