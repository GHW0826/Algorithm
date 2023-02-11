#include <iostream>
#include <vector>
using namespace std;

int N;
int tmp = 0;
int order[6][4] = {
    { 1, 2, 3, 4 },
    { 0, 2, 4, 5 },
    { 0, 1, 3, 5 },
    { 0, 2, 4, 5 },
    { 0, 1, 3, 5 },
    { 1, 2, 3, 4 }
};

int topBottom[6] = { 5, 3, 4, 1, 2, 0 };

void dfs(vector<vector<int>>& map, int top, int depth) {

    if (depth >= N)
        return;

    for (int i = 0; i < 6; ++i) {
        if (map[depth][i] == top) {
            int max = 0;
            for (int j = 0; j < 4; ++j)
                if (max < map[depth][order[i][j]])
                    max = map[depth][order[i][j]];
            tmp += max;
            dfs(map, map[depth][topBottom[i]], depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    vector<vector<int>> map(N, vector<int>(6, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> map[i][j];

    int answer = 0;
    for (int j = 0; j < 6; ++j) {
        dfs(map, map[0][j], 0);
        if (answer < tmp)
            answer = tmp;
        tmp = 0;
    }

    cout << answer << endl;

    return 0;

}
