  - 1043
```cpp

#include <iostream>
#include <vector>
using namespace std;



// 1043
vector<int> group;

int find(int x) {
    if (group[x] == x)
        return x;
    return x = find(group[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    group[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int known_num;
    cin >> known_num;

    vector<int> known_human(known_num);
    for (int i = 0; i < known_num; ++i)
        cin >> known_human[i];

    vector<vector<int>> party(M, vector<int>());
    for (int i = 0; i < M; ++i) {
        int cnt, id;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            cin >> id;
            party[i].push_back(id);
        }
    }

    for (int i = 0; i <= N; ++i)
        group.push_back(i);

    for (int i = 0; i < M; ++i) {
        int n1 = party[i][0];
        for (int j = 1; j < party[i].size(); ++j) {
            int n2 = party[i][j];
            Union(n1, n2);
        }
    }

    int answer = 0;
    for (int i = 0; i < M; i++) {
        bool flag = false;
        for (int j = 0; j < party[i].size(); j++) {
            int n1 = party[i][j];
            for (int k = 0; k < known_human.size(); k++) {
                if (find(n1) == find(known_human[k])) {
                    flag = true;
                    break;
                }
            }
            if (flag) 
                break;
        }
        if (!flag)
            ++answer;
    }

    cout << answer << '\n';
    return 0;
}
```

  - 2252
```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


stack<int> s;
void dfs(vector<vector<int>>& graph, vector<int>& visit, int node) {
    visit[node] = true;
    for (int i = 0; i < graph[node].size(); ++i) {
        int target = graph[node][i];
        if (visit[target] == false)
            dfs(graph, visit, target);
    }
    s.push(node);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> visit(N + 1, false);
    vector<vector<int>> graph(N + 1, vector<int>());
    for (int i = 0; i < M; ++i) {
        int compare1, compare2;
        cin >> compare1 >> compare2;
        graph[compare1].push_back(compare2);
    }

    for (int i = 1; i <= N; ++i) {
        if (visit[i] == false)
            dfs(graph, visit, i);
    }

    while (s.empty() == false) {
        cout << s.top() << " ";
        s.pop();
    }
}
```

  - 1516
```cpp

```
