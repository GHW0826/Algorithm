#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int H, M, N;

int dx[6] = { -1, 0, 1, 0, 0, 0 };
int dy[6] = { 0, -1, 0, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

struct Info {
    int x_;
    int y_;
    int z_;
    int time_;

    Info(int x, int y, int z, int time) {
        x_ = x;
        y_ = y;
        z_ = z;
        time_ = time;
    }
};

bool isInMap(int x, int y, int z) {
    return (x < 0 || x >= H || y < 0 || y >= M || z < 0 || z >= N) == false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> H >> M >> N;

    vector<vector<vector<int>>> tomato(N, vector<vector<int>>(M, vector<int>(H)));
    vector<vector<vector<bool>>> visit(N, vector<vector<bool>>(M, vector<bool>(H)));

    queue<Info> q;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < H; ++k) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) {
                    q.push(Info(k, j, i, 0));
                    visit[i][j][k] = true;
                }
            }
        }
    }

    int answer = 0;
    while (q.empty() == false) {
        int x = q.front().x_;
        int y = q.front().y_;
        int z = q.front().z_;
        int time = q.front().time_;
        q.pop();

        if (answer < time)
            answer = time;

        for (int i = 0; i < 6; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            int nextZ = z + dz[i];
            if (isInMap(nextX, nextY, nextZ) == true) {
                if (tomato[nextZ][nextY][nextX] == 0 && visit[nextZ][nextY][nextX] == false) {
                    visit[nextZ][nextY][nextX] = true;
                    q.push(Info(nextX, nextY, nextZ, time + 1));
                }
            }
        }
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < H; ++k)
                if (tomato[i][j][k] != -1 && visit[i][j][k] == false)
                    answer = -1;
    cout << answer << endl;
    return 0;
}
