#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info {
    int x;
    int y;
public:
    info(int x, int y) : x(x), y(y) {}
};

int row, col;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<vector<int>> map;
queue<info> q;

bool isInMap(int x, int y) {
    return (x < 0 || x >= col || y < 0 || y >= row) == false;
}

void slice(int x, int y, vector<vector<bool>>& visit) {
    for (int k = 0; k < 4; ++k) {
        int nextX = x + dx[k];
        int nextY = y + dy[k];
        if (isInMap(nextX, nextY) == true) {
            if (visit[nextY][nextX] == false) {
                visit[nextY][nextX] = true;
                if (map[nextY][nextX] == 1)
                    continue;

                if (map[nextY][nextX] == 0)
                    q.push(info(nextX, nextY));
                slice(nextX, nextY, visit);
            }
        }
    }
}

void melt() {

    while (q.empty() == false) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nextX = x + dx[k];
            int nextY = y + dy[k];
            if (isInMap(nextX, nextY) == true)
                map[nextY][nextX] = 0;
        }
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col;

    int cnt = 0;
    map.resize(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 1)
                ++cnt;
        }
    }

    int answer = 0;
    int before = cnt;
    while (cnt > 0) {
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        slice(0, 0, visit);
        melt();

        ++answer;
        before = cnt;
        cnt = 0;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (map[i][j] == 1)
                    ++cnt;
    }

    cout << answer << endl;
    cout << before << endl;

    return 0;
}
