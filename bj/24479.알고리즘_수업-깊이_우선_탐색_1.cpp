#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> order;
vector<bool> visit;
vector<set<int>> graph;
int orders = 1;
void dfs(vector<set<int>>& graph, vector<bool>& visit, int start)
{
    visit[start] = true;
    order[start] = orders++;
    for (auto& it : graph[start])
        if (visit[it] == false)
            dfs(graph, visit, it);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int node, line, start;
    cin >> node >> line >> start;

    order.resize(node + 1, 0);
    visit.resize(node + 1, false);
    graph.resize(node + 1, set<int>());
    int node1, node2;
    for (int i = 0; i < line; ++i) {
        cin >> node1 >> node2;
        graph[node1].insert(node2);
        graph[node2].insert(node1);
    }

    dfs(graph, visit, start);
    for (int i = 1; i < order.size(); ++i)
        cout << order[i] << "\n";

    return 0;
}
