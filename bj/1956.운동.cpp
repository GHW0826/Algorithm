
#include <iostream>
#include <vector>
using namespace std;

int mapSize;
vector<vector<long long>> map;
long long INF = 9876543210;
void floydwarshall() {
    for (int i = 1; i <= mapSize; ++i)
        for (int j = 1; j < mapSize; ++j)
            for (int k = 1; k <= mapSize; ++k)
                map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    cin >> V >> E;

    int start, end, weight;
    mapSize = V;
    map.resize(V + 1, vector<long long>(V + 1, INF));
    for (int i = 0; i < E; ++i) {
        cin >> start >> end >> weight;
        map[start][end] = weight;
    }

    floydwarshall();

    long long answer = INF;
    for (int i = 1; i <= mapSize; ++i)
        for (int j = 1; j <= mapSize; ++j)
            if (i == j)
                answer = min(answer, map[i][i]);

    if (answer == INF)
        answer = -1;
    cout << answer << endl;
    return 0;
}
