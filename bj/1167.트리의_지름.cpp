#include <iostream>
#include <vector>
using namespace std;

int each_dist = 0;
int max_node = 0;

void dfs(vector<vector<pair<int, int>>>& map, vector<bool>& visit, int start, int dist) {

    if (visit[start] == true)
        return;

    if (dist > each_dist) {
        each_dist = dist;
        max_node = start;
    }

    visit[start] = true;
    for (int i = 0; i < map[start].size(); ++i)
        dfs(map, visit, map[start][i].first, dist + map[start][i].second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int node;
    cin >> node;

    vector<vector<pair<int, int>>> map(node, vector<pair<int, int>>());
    int start_node, connect_node = 0, weight;
    for (int i = 0; i < node; ++i) {
        cin >> start_node;

        while (1) {
            cin >> connect_node;
            if (connect_node == -1)
                break;
            cin >> weight;
            map[start_node - 1].push_back(make_pair(connect_node - 1, weight));
        }
    }

    // 0번투 시작점 다돌리면 시간 초과.
    // 무작위 점 하나에서 가장 먼 노드를 찾는다.
    // 그곳에서 가장 먼 거리가 트리의 지름.
    vector<bool> visit(node, false);
    dfs(map, visit, 0, 0);

    std::fill(visit.begin(), visit.end(), false);
    dfs(map, visit, max_node, 0);
    cout << each_dist << "\n";
    return 0;
}
