#include <iostream>
#include <vector>
using namespace std;

vector<bool> visit;
vector<vector<int>> graph;
int answer = -1;

void dfs(int start)
{
    ++answer;
    visit[start] = true;
    for (int i = 0; i < graph[start].size(); ++i)
        if (visit[graph[start][i]] == false)
            dfs(graph[start][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int computer, line;
    cin >> computer >> line;

    int computer1, computer2;
    visit.resize(computer + 1, false);
    graph.resize(computer + 1, vector<int>());
    for (int i = 0; i < line; ++i) {
        cin >> computer1 >> computer2;
        graph[computer1].push_back(computer2);
        graph[computer2].push_back(computer1);
    }

    dfs(1);

    cout << answer << "\n";
    return 0;
}
