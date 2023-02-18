#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int max_weight = 987654321;
int N, M;

void floydWarshall(vector<vector<int>>& map) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                if (map[j][i] != max_weight && map[i][k] != max_weight)
                    map[j][k] = min(map[j][i] + map[i][k], map[j][k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;


    vector<vector<int>> map(N + 1, vector<int>(N + 1, max_weight));
    for (int i = 0; i < N; ++i)
        map[i][i] = 0;
    for (int i = 0; i < M; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        map[start - 1][end - 1] = min(map[start - 1][end - 1], weight);
    }

    floydWarshall(map);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << ((map[i][j] == max_weight) ? 0 : map[i][j]) << " ";
        cout << "\n";
    }

    return 0;

}
