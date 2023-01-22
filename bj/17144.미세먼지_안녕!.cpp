#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info {
    int x;
    int y;
    int amount;
public:
    info(int x, int y, int amount) : x(x), y(y), amount(amount) {}
};

int R, C, T;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<pair<int, int>> cleanPos;
vector<vector<int>> map;
queue<info> q;



bool isInMap(int x, int y) {
    return (x < 0 || x >= C || y < 0 || y >= R) == false;
}

void spread() {
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (map[i][j] > 0)
                q.push(info(j, i, map[i][j] / 5));

    while (q.empty() == false) {
        int x = q.front().x;
        int y = q.front().y;
        int amount = q.front().amount;
        q.pop();

        int spreadCnt = 0;
        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (isInMap(nextX, nextY) == true) {
                if (map[nextY][nextX] != -1) {
                    map[nextY][nextX] += amount;
                    ++spreadCnt;
                }
            }
        }
        map[y][x] -= amount * spreadCnt;
    }
}

void rotateTop() {
    int x = cleanPos[0].first;
    int y = cleanPos[0].second;

    // 좌변
    for (int i = y; i > 0; --i)
        if (map[i][0] != -1)
            map[i][0] = map[i - 1][0];

    // 상변
    for (int i = 0; i < C - 1; ++i)
        map[0][i] = map[0][i + 1];

    // 우변
    for (int i = 0; i < y; ++i)
        map[i][C - 1] = map[i + 1][C - 1];

    // 하변
    for (int i = C - 1; i > 0; --i) {
        if (map[y][i - 1] != -1)
            map[y][i] = map[y][i - 1];
        else
            map[y][i] = 0;
    }
}

void rotateBottom() {
    int x = cleanPos[1].first;
    int y = cleanPos[1].second;

    // 좌변
    for (int i = y; i < R - 1; ++i)
        if (map[i][0] != -1)
            map[i][0] = map[i + 1][0];

    // 하변
    for (int i = 0; i < C - 1; ++i)
        map[R - 1][i] = map[R - 1][i + 1];

    // 우변
    for (int i = R - 1; i > y; --i)
        map[i][C - 1] = map[i - 1][C - 1];

    // 상변
    for (int i = C - 1; i > 0; --i) {
        if (map[y][i - 1] != -1)
            map[y][i] = map[y][i - 1];
        else
            map[y][i] = 0;
    }
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> T;

    map.resize(R, vector<int>(C, 0));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> map[i][j];
            if (map[i][j] == -1)
                cleanPos.emplace_back(make_pair(j, i));
        }
    }

    for (int i = 0; i < T; ++i) {
        spread();
        rotateTop();
        rotateBottom();
    }

    int answer = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (map[i][j] != -1)
                answer += map[i][j];

    cout << answer << endl;

    return 0;
}1
