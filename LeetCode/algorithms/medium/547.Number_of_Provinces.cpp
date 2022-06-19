class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visit;

    void dfs(int start) {
        for (int i = 0; i < graph[start].size(); ++i) {
            if (visit[graph[start][i]] == false) {
                visit[graph[start][i]] = true;
                dfs(graph[start][i]);
            }
        }
    }

    int findCircleNum(vector<vector<int>> isConnected) {
        visit.resize(isConnected.size(), false);
        graph.resize(isConnected.size(), vector<int>());

        for (int i = 0; i < isConnected.size(); ++i)
            for (int j = 0; j < isConnected[i].size(); ++j)
                if (i != j)
                    if (isConnected[i][j] == 1)
                        graph[i].push_back(j);

        int answer = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (visit[i] == false) {
                ++answer;
                dfs(i);
            }
        }
        return answer;
    }
};
