#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<bool> visit;
vector<set<int>> graph;
int answer = -1;

void dfs(int start)
{
    ++answer;
    visit[start] = true;
    for (auto& it : graph[start])
        if (visit[it] == false)
            dfs(it);
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
    graph.resize(computer + 1, set<int>());
    for (int i = 0; i < line; ++i) {
        cin >> computer1 >> computer2;
        graph[computer1].insert(computer2);
        graph[computer2].insert(computer1);
    }

    dfs(1);

    cout << answer << "\n";
    return 0;
}
