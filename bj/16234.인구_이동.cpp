#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int acc = 0;
int N, L, R;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct info {
    int x;
    int y;
public:
    info(int x, int y) : x(x), y(y) {}
};

bool isInMap(int x, int y) {
    return (x < 0 || x >= N || y < 0 || y >= N) == false;
}

bool canMove(int x, int y, int nextX, int nextY, vector<vector<int>>& map) {
    int max = std::max(map[y][x], map[nextY][nextX]);
    int min = std::min(map[y][x], map[nextY][nextX]);
    int comp = max - min;
    return ((L <= comp) && (comp <= R)) == true;
}

void dfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visit, queue<info>& q) {
    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isInMap(nextX, nextY) == true) {
            if (visit[nextY][nextX] == false && canMove(x, y, nextX, nextY, map) == true) {
                visit[nextY][nextX] = true;
                q.push(info(nextX, nextY));
                acc += map[nextY][nextX];
                dfs(nextX, nextY, map, visit, q);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L >> R;

    vector<vector<int>> map(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];

    int answer = 0;
    int resetCnt = 0;
    while (1) {

        vector<vector<bool>> visit(N, vector<bool>(N, false));
        queue<info> q;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (visit[j][i] == false) {
                    visit[j][i] = true;
                    q.push(info(i, j));
                    acc += map[j][i];
                    dfs(i, j, map, visit, q);

                    if (q.size() > 1)
                        ++resetCnt;
                    int people = acc / q.size();
                    while (q.empty() == false) {
                        int setX = q.front().x;
                        int setY = q.front().y;
                        map[setY][setX] = people;
                        q.pop();
                    }
                    acc = 0;
                }
            }
        }
        if (resetCnt > 0)
            resetCnt = 0;
        else
            break;

        ++answer;
    }

    cout << answer << endl;

    return 0;
}
