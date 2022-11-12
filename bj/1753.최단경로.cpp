#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int row, col;
vector<vector<long long>> dp;

bool isInMap(int x, int y, int col, int row) {
    return (x < 0 || x >= col || y < 0 || y >= row) == false;
}

int dfs(int x, int y, vector<vector<int>>& map) {

    if (x == col - 1 && y == row - 1)
        return 1;
    else if (dp[y][x] != -1) 
        return dp[y][x];

    dp[y][x] = 0;
    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isInMap(nextX, nextY, col, row) == true)
            if (map[y][x] > map[nextY][nextX])
                dp[y][x] = dp[y][x] + dfs(nextX, nextY, map);
    }
    return dp[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;

    vector<vector<int>> map;
    for (int i = 0; i < row; ++i) {
        vector<int> row(col);
        vector<long long> dp_row(col, -1);
        for (int j = 0; j < col; ++j)
            cin >> row[j];
        map.emplace_back(row);
        dp.emplace_back(dp_row);
    }

    cout << dfs(0, 0, map) << endl;
    return 0;
}
