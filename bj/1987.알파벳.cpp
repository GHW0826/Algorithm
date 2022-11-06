#include <queue>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;
int r, c;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<bool> alph(26, false);

bool isInMap(int x, int y, int row, int col) {
    return (x < 0 || x >= col || y < 0 || y >= row) == false;
}

void dfs(int col, int row, vector<string>& map, int dist) {

    if (answer < dist)
        answer = dist;
    for (int i = 0; i < 4; ++i) {
        int nextX = col + dx[i];
        int nextY = row + dy[i];
        if (isInMap(nextX, nextY, r, c)) {
            if (alph[map[nextY][nextX] - 65] == false) {
                alph[map[nextY][nextX] - 65] = true;
                dfs(nextX, nextY, map, dist + 1);
                alph[map[nextY][nextX] - 65] = false;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;

    vector<string> map(r);
    for (int i = 0; i < r; ++i)
        cin >> map[i];

    alph[map[0][0] - 65] = true;
    dfs(0, 0, map, 1);
    cout << answer << endl;
    return 0;
}
