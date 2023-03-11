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

int N, M;
const int dummyMax = 987654321;
int answer = dummyMax;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<vector<int>> map;
vector<vector<info>> pickPos;
queue<info> q;
vector<info> pos;

bool isInMap(int x, int y) {
    return (x < 0 || x >= N || y < 0 || y >= N) == false;
}

void ncr(int index, vector<info>& pick, int depth) {
    if (depth == M)
        pickPos.push_back(pick);
    for (int i = index; i < pos.size(); ++i) {
        pick.push_back(pos[i]);
        ncr(i + 1, pick, depth + 1);
        pick.pop_back();
    }
}

void bfs(int order) {

    vector<vector<int>> copyMap = map;
    for (int i = 0; i < pickPos[order].size(); ++i) {
        int x = pickPos[order][i].x;
        int y = pickPos[order][i].y;
        copyMap[y][x] = 2;
        q.push(info(x, y));
    }

    vector<vector<int>> mapDist(N, vector<int>(N, 0));
    vector<vector<bool>> visit(N, vector<bool>(N, false));
    while (q.empty() == false) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nextX = x + dx[k];
            int nextY = y + dy[k];
            if (isInMap(nextX, nextY) == true) {
                if (visit[nextY][nextX] == false && copyMap[nextY][nextX] == 0) {
                    mapDist[nextY][nextX] = mapDist[y][x] + 1;
                    visit[nextY][nextX] = true;
                    q.push(info(nextX, nextY));
                }
            }
        }
    }

    int second = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (mapDist[i][j] > second)
                second = mapDist[i][j];
            if (mapDist[i][j] == 0 && copyMap[i][j] != 2 && copyMap[i][j] != -1) {
                second = 987654321;
                break;
            }
        }
    }

    answer = min(second, answer);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    map.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                pos.push_back(info(j, i));
                map[i][j] = 0;
            }
            else if (map[i][j] == 1)
                map[i][j] = -1;
        }
    }

    vector<info> pick;
    ncr(0, pick, 0);
    for (int i = 0; i < pickPos.size(); ++i)
        bfs(i);

    if (answer == dummyMax)
        answer = -1;
    cout << answer << endl;

    return 0;
}
