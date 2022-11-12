#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF 987654321
using namespace std;

map<int, vector<pair<int, int>>> graph;
vector<int> d;
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    while (pq.empty() == false) {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (d[cur] < dist)
            continue;
        for (int i = 0; i < graph[cur].size(); ++i) {
            int nextDist = dist + graph[cur][i].first;
            int next = graph[cur][i].second;
            if (d[next] > nextDist) {
                d[next] = nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int node, edge, start;
    cin >> node >> edge >> start;
    for (int i = 0; i < node + 1; ++i)
        d.push_back(INF);
    for (int i = 0; i < edge; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start].emplace_back(make_pair(weight, end));
    }

    dijkstra(start);

    for (int i = 1; i < node + 1; ++i) {
        if (d[i] == INF)
            cout << "INF" << " ";
        else
            cout << d[i] << " ";
    }
    return 0;
}
