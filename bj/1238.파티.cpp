#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

void dijkstra(int start, vector<vector<pair<int, int>>>& map, vector<vector<int>>& dists) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dists[start][start] = 0;
    while (pq.empty() == false) {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dists[start][cur] < dist)
            continue;
        for (int i = 0; i < map[cur].size(); ++i) {
            int nextDist = dist + map[cur][i].first;
            int next = map[cur][i].second;
            if (dists[start][next] > nextDist) {
                dists[start][next] = nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<int>> dists(N + 1, vector<int>(N + 1, INF));
    vector<vector<pair<int, int>>> map(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; ++i) {
        int start, target, dist;
        cin >> start >> target >> dist;
        map[start].push_back(make_pair(dist, target));
    }

    for (int i = 1; i < N + 1; ++i)
        dijkstra(i, map, dists);

    int answer = -1;
    for (int start = 1; start < N + 1; ++start)
        if (dists[start][X] + dists[X][start] > answer)
            answer = dists[start][X] + dists[X][start];
    cout << answer << endl;
    return 0;
}
