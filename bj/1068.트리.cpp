#include <iostream>
#include <vector>
using namespace std;

int N;
int cut;
int answer = 0;
vector<vector<int>> tree;

void dfs(int cur) {
    if (cur == cut)
        return;
    if (tree[cur].size() == 0)
        ++answer;

    for (int i = 0; i < tree[cur].size(); ++i) {
        dfs(tree[cur][i]);
        if (tree[cur][i] == cut && tree[cur].size() == 1)
            ++answer;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    tree.resize(N, vector<int>());
    int parent;
    int root = 0;
    for (int i = 0; i < N; ++i) {
        cin >> parent;
        if (parent == -1)
            root = i;
        else
            tree[parent].push_back(i);
    }
    cin >> cut;

    if (cut == root)
        answer = 0;
    else
        dfs(root);
    cout << answer << endl;

    return 0;
}
