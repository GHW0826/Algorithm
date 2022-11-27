#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visit, vector<int>& cnt) {
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (q.empty() == false) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); ++i) {
            if (visit[graph[cur][i]] == false) {
                cnt[start]++;
                visit[graph[cur][i]] = true;
                q.push(graph[cur][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>());
    int con1, con2;
    for (int i = 0; i < M; ++i) {
        cin >> con1 >> con2;
        graph[con2].push_back(con1);
    }
    
    vector<int> cnt(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        vector<bool> visit(N + 1, false);
        bfs(i, graph, visit, cnt);
    }

    int max = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < cnt.size(); ++i)
        if (cnt[i] == max)
            cout << i << " ";
    return 0;
}
