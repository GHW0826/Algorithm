#include <string>
#include <vector>

using namespace std;

int dfs(int start, vector<vector<int>>& graph, vector<bool>& visit) {

    int nodes = 0;
    for (int i = 0; i < graph[start].size(); ++i) {
        if (visit[graph[start][i]] == false) {
            ++nodes;
            visit[graph[start][i]] = true;
            nodes += dfs(graph[start][i], graph, visit);
        }
    }

    return nodes;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = wires.size();
    for (int i = 0; i < wires.size(); ++i) {
        vector<bool> visit(n + 1, false);
        vector<vector<int>> graph(n + 1, vector<int>());
        for (int j = 0; j < wires.size(); ++j) {
            if (i == j)
                continue;
            graph[wires[j][0]].push_back(wires[j][1]);
            graph[wires[j][1]].push_back(wires[j][0]);
        }

        int nodes = 0;
        for (int j = 0; j < graph.size(); ++j) {
            for (int k = 0; k < graph[j].size(); ++k) {
                if (visit[graph[j][k]] == false) {
                    nodes = dfs(graph[j][k], graph, visit);
                }
            }
        }

        answer = min(answer, abs(n - (2 * nodes)));
    }

    return answer;
}
