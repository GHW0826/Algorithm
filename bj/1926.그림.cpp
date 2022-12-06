#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cnt = 0;
int maxSize = 0;
int dx[4] = { -1,  0, 1, 0 };
int dy[4] = {  0, -1, 0, 1 };
bool isInMap(int x, int y) {
  return (x < 0 || x >= m || y < 0 || y >= n) == false;
}

int dfs(int x, int y, vector<vector<int>>& pic, vector<vector<bool>>& visit) {
  visit[y][x] = true;
  int size = 1;
  for (int i = 0; i < 4; ++i) {
    int nextX = x + dx[i];
    int nextY = y + dy[i];
    if (isInMap(nextX, nextY) == true)
      if (visit[nextY][nextX] == false && pic[nextY][nextX] != 0)
        size += dfs(nextX, nextY, pic, visit);
  }
  
  return size;
}

int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  vector<vector<int>> pic;
  vector<vector<bool>> visit(n, vector<bool>(m, false));
  for (int i = 0; i < n; ++i) {
    vector<int> row(m);
    for (int j = 0; j < m; ++j)
      cin >> row[j];
    pic.emplace_back(row);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (visit[i][j] == false && pic[i][j] != 0) {
        ++cnt;
        int size = dfs(j, i, pic, visit);
        if (size > maxSize)
            maxSize = size;
      }
    }
  }
  cout << cnt << endl;
  cout << maxSize << endl;

  return 0;
}
