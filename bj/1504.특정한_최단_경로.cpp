#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

int INF = 987654321;
int answer = 987654321;
int N, E;
int require1, require2;

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<vector<int>>& dists) {
    dists[start][start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (pq.empty() == false) {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); ++i) {
            int nextDist = graph[cur][i].first;
            int next = graph[cur][i].second;
            if (dists[start][next] > nextDist + dist) {
                dists[start][next] = nextDist + dist;
                pq.push(make_pair(-dists[start][next], next));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> E;

    int start, end, weight;
    vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < E; ++i) {
        cin >> start >> end >> weight;
        graph[start].push_back(make_pair(weight, end));
        graph[end].push_back(make_pair(weight, start));
    }
    cin >> require1 >> require2;

    vector<vector<int>> dists(N + 1, vector<int>(N + 1, INF));
    dijkstra(1, graph, dists);
    dijkstra(require1, graph, dists);
    dijkstra(require2, graph, dists);

    answer = min(answer, dists[1][require1] + dists[require1][require2] + dists[require2][N]);
    answer = min(answer, dists[1][require2] + dists[require2][require1] + dists[require1][N]);
    if (dists[1][require1] == INF ||  dists[require1][require2] == INF || dists[require2][N] == INF)
        answer = -1;

    cout << answer << endl;
    return 0;
}
