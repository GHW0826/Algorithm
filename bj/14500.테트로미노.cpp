
#include <iostream>
#include <vector>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int row, col;
int answer = 0;

void dfs(int y, int x, int sum, int cnt, vector<vector<int>>& map, vector<vector<bool>>& visited) {
    if (cnt == 4) {
        answer = max(answer, sum);
        return;
    }

    if (y < 0 || x < 0 || y >= row || x >= col) 
      return;

    if (visited[y][x]) return;

    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
        dfs(y + dy[i], x + dx[i], sum + map[y][x], cnt + 1, map, visited);
    visited[y][x] = false;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col;

    vector<vector<int>> map(row, vector<int>(col));
    vector<vector<bool>> visit(row, vector<bool>(col));

    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            cin >> map[i][j];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            dfs(i, j, 0, 0, map, visit);

            // 예외 처리
            if (j + 2 < col) {
                int tmp = map[i][j] + map[i][j + 1] + map[i][j + 2];
                if (i - 1 >= 0)
                    answer = max(answer, tmp + map[i - 1][j + 1]);
                if (i + 1 < row)
                    answer = max(answer, tmp + map[i + 1][j + 1]);
            }
            if (i + 2 < row) {
                int tmp = map[i][j] + map[i + 1][j] + map[i + 2][j];
                if (j - 1 >= 0)
                    answer = max(answer, tmp + map[i + 1][j - 1]);
                if (j + 1 < col)
                    answer = max(answer, tmp + map[i + 1][j + 1]);
            }
        }
    }
  
    cout << answer << '\n';
    return 0;
}
