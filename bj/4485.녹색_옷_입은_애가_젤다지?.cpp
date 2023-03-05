#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool isInMap(int x, int y) {
    return (x < 0 || x >= N || y < 0 || y >= N) == false;
}

struct info {
    int x;
    int y;
public:
    info(int x, int y) : x(x), y(y) {}
};

void bfs(vector<vector<int>>& map, vector<vector<int>>& dist) {
    queue <info> q;
    q.push(info(0,0));
    dist[0][0] = map[0][0];

    while (q.empty() == false) {

        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (isInMap(nextX, nextY) == true) {
                if (dist[nextY][nextX] > dist[y][x] + map[nextY][nextX]) {
                    dist[nextY][nextX] = dist[y][x] + map[nextY][nextX];
                    q.push(info(nextX, nextY));
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 1;
    while (1) {
        cin >> N;
        if (N == 0)
            break;

        vector<vector<int>> map(N, vector<int>(N, 0));
        vector<vector<int>> dist(N, vector<int>(N, 987654321));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> map[i][j];

        bfs(map, dist);
        cout << "Problem " << cnt << ": " << dist[N - 1][N - 1] << "\n";
        ++cnt;
    }

    return 0;
}
