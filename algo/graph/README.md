
-----------------------------------------
## 경로 탐색

- 다익스트라 (Dijkstra) 알고리즘
```
  반복문 : O(n^2)
  우선순위 큐 : O(E * logN)  // E : 간선 수, N : 정점 수
  
  두 노드의 최단 거리를 찾을때 사용.
  간선 비용에 음수가 있으면 안된다. 음수가 없는 현실 세계에서 사용하기 좋다.
  
  1. 출발 노드를 선택
  2. 최단 거리 테이블 초기화
  3. 방문하지 않은 노드 중 시작 노드와 최단 거리가 가장 짧은 노드를 선택
  4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산해 최단 거리 테이블 업데이트
  
  3~4 반복.
```

  - 1. 반복문 이용
```cpp
int start = 0;          // 시작 노드 위치
int size = 10;          // 그래프 노드 갯수
int dist[size];         // 시간노드에서 해당 노드들까지의 최소거리
bool visit[size];       // 해당 위치 노드 방문 여부
int table[size][size];  // 최단 거리 테이블.

// 3번 과정
// 방문하지 않은 노드중 시작노드와 최단거리 짧은 노드 선택
int min_weight_node()
{
  int pos = -1, min = INT_MAX;
  
  for (int i = 0; i < size; ++i) {
    if (dist[i] < min && visit[i] == false) {
      min = dist[i];
      pos = i;
    }
  }
  return pos;
}

void Dijkstra()
{
  table...; // 최단거리 테이블 초기화 (그래프 전체 연결 가중치 정보)
  visit...; // 노드 방문 초기화 (false)
  dist...;  // 시작 노드에서 인접한 노드들 거리 기본 초기화 
  
  // 시작 노드 정보
  visit[start] = true;
  dist[0] = 0;
  
  int node = -1;
  for (int i = 0; i < size; ++i) {
    node = min_weight_node();
    visit[node] = true;
    
    // 시작 노드에서 걸리는 비용 갱신
    for (int j = 0; j < size; ++j) {
      if (visit[j] == false)
        if (dist[node] + table[node][j] < dist[j])
          dist[j] = dist[node] + table[node][j];
    }
  }
}
```
  - 2. 우선순위 큐 이용.
```cpp
int start = 0;          // 시작 노드 위치
int size = 10;          // 그래프 노드 갯수
int dist[size];         // 시간노드에서 해당 노드들까지의 최소거리
int table[size][size];  // 최단 거리 테이블.

void Dijkstra()
{
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));
  dist[start] = 0;
  
  while (pq.empty() == false) {
    // -붙여서 넣어서 바꿔줌.
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    
    for (int i = 0; i < size; ++i) {
      // 노드가 연결되어 있으면.
      if (table[cur][i] != -1) {
        int dist = table[cur][i] + cost;
        if (dist < dist[cur]) {
          dist[cur] = dist;
          pq.push(make_pair(-dist, j));
          // -로 넣는 이유는 stl은 가장 큰 원소가 위로 가도록 큐를 구성. 부호 바꿔서 작은 정점부터 꺼낼려고.
        }
      }
    }
  }
}
```

- 플로이드 워셜 (Floyd-Warshall) 알고리즘
- 벨만 포드 (Bellman-Ford's) 알고리즘
