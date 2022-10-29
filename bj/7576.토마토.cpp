#include <queue>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool isInMap(int x, int y, int row, int col) {
    return (x < 0 || x >= col || y < 0 || y >= row) == false;
}
enum pos {
    x = 0,
    y = 1
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int col, row;
    cin >> col >> row;

    queue<tuple<int, int>> q;
    vector<vector<int>> map;
    for (int i = 0; i < row; ++i) {
        vector<int> row(col, 0);
        for (int j = 0; j < col; ++j) {
            cin >> row[j];
            if (row[j] == 1)
                q.push(make_tuple(j, i));
        }
        map.emplace_back(row);
    }

    while (q.empty() == false) {
        auto val = q.front();
        auto x = get<pos::x>(val);
        auto y = get<pos::y>(val);
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (isInMap(nextX, nextY, row, col) == true) {
                if (map[nextY][nextX] == 0) {
                    map[nextY][nextX] = map[y][x] + 1;
                    q.push(make_tuple(nextX, nextY));
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (answer < map[i][j]) {
                answer = map[i][j];
            }
        }
    }

    cout << answer - 1 << endl;

    return 0;
}
