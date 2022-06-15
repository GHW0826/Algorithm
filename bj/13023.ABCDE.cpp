#include <iostream>
#include <vector>
using namespace std;

vector<bool> visit;
vector<vector<int>> graph;
bool answer = false;

void dfs(int start, int depth) 
{
    if (depth == 4) {
        answer = true;
        return;
    }

    for (int i = 0; i < graph[start].size(); ++i) {
        if (visit[graph[start][i]] == false) {
            visit[start] = true;
            dfs(graph[start][i], depth + 1);
            visit[start] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int node1, node2;
    visit.resize(N, false);
    graph.resize(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for (int i = 0; i < N; ++i) {
        fill(visit.begin(), visit.end(), false);
        dfs(i, 0);
        if (answer == true)
            break;
    }

    cout << (answer == true ? "1" : "0") << "\n";

    return 0;
}
