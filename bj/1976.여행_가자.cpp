#include <iostream>
#include <vector>
#include <string>
using namespace std;

int group[205];
int path[1005];

int find(int x) {
  if (group[x] == x)
    return x;
  group[x] = find(group[x]);
  return group[x];
}

void Union(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    if (x < y)
      group[y] = x;
    else
      group[x] = y;
  }
}


int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; ++i)
    group[i] = i;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      int exists = 0;
      cin >> exists;
      if (exists == 1)
        Union(i, j);
    }
  }

  for (int i = 0; i < M; ++i)
    cin >> path[i];

  string answer = "YES";
  for (int i = 0; i < M - 1; ++i) {
    if (find(path[i]) != find(path[i+1])) {
      answer = "NO";
      break;
    }
  }

  cout << answer << endl;

  return 0;
}
