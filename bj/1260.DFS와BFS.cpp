#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<set<int>> graph;
vector<bool> dfs_visit;
vector<bool> bfs_visit;
vector<int> dfs_answer;
vector<int> bfs_answer;

void dfs(int start)
{
    dfs_answer.push_back(start);
    dfs_visit[start] = true;
    for (auto& it : graph[start])
        if (dfs_visit[it] == false)
            dfs(it);
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    bfs_visit[start] = true;
    while (q.empty() == false) {
        int node = q.front();
        q.pop();
        bfs_answer.push_back(node);
        for (auto& it : graph[node])
            if (bfs_visit[it] == false) {
                bfs_visit[it] = true;
                q.push(it);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    int node1, node2;
    graph.resize(N + 1, set<int>());
    dfs_visit.resize(N + 1, false);
    bfs_visit.resize(N + 1, false);
    for (int i = 0; i < M; ++i) {
        cin >> node1 >> node2;
        graph[node1].insert(node2);
        graph[node2].insert(node1);
    }

    dfs(V);
    bfs(V);

    for (auto& it : dfs_answer)
        cout << it << " ";
    cout << "\n";
    for (auto& it : bfs_answer)
        cout << it << " ";
    return 0;
}
