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
    cin >> row >> col;

    queue<tuple<int, int>> q;
    vector<tuple<int, int>> canWall;
    vector<vector<int>> map;
    for (int i = 0; i < row; ++i) {
        vector<int> row(col, 0);
        for (int j = 0; j < col; ++j) {
            cin >> row[j];
            if (row[j] == 2)
                q.push(make_tuple(j, i));
            else if (row[j] == 0)
                canWall.emplace_back(make_tuple(j, i));
        }
        map.emplace_back(row);
    }

    int answer = 0;
    vector<int> temp(canWall.size(), 0);
    temp[0] = temp[1] = temp[2] = 1;
    do {
        vector<vector<int>> map2(map);
        for (int i = 0; i < canWall.size(); ++i)
            if (temp[i] == 1)
                map2[get<pos::y>(canWall[i])][get<pos::x>(canWall[i])] = 1;

        vector<vector<bool>> visit(row, vector<bool>(col, false));
        queue<tuple<int, int>> q2(q);
        while (q2.empty() == false) {
            auto val = q2.front();
            auto x = get<pos::x>(val);
            auto y = get<pos::y>(val);
            q2.pop();

            for (int i = 0; i < 4; ++i) {
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                if (isInMap(nextX, nextY, row, col) == true) {
                    if (map2[nextY][nextX] == 0) {
                        map2[nextY][nextX] = 2;
                        q2.push(make_tuple(nextX, nextY));
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (map2[i][j] == 0)
                    ++cnt;
        if (cnt > answer)
            answer = cnt;
    } while (prev_permutation(temp.begin(), temp.end()));

    cout << answer << endl;

    return 0;
}
