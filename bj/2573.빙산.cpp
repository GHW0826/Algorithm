#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct meltAction {
    int x;
    int y;
    int amount;
public:
    meltAction(int x, int y, int amount) {
        this->x = x;
        this->y = y;
        this->amount = amount;
    }
};

bool isInMap(int x, int y) {
    return (x < 0 || x >= M || y < 0 || y >= N) == false;
}

void melt() {
    queue<meltAction> q;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] != 0) {
                int amount = 0;
                for (int k = 0; k < 4; ++k) {
                    int checkX = j + dx[k];
                    int checkY = i + dy[k];
                    if (isInMap(checkX, checkY) == true)
                        if (map[checkY][checkX] == 0)
                            ++amount;
                }
                q.push(meltAction(j, i, amount));
            }
        }
    }
    while (q.empty() == false) {
        auto action = q.front();
        q.pop();
        map[action.y][action.x] -= action.amount;
        if (map[action.y][action.x] < 0)
            map[action.y][action.x] = 0;
    }
}

void dfs(int x, int y, vector<vector<bool>>& visit) {

    visit[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isInMap(nextX, nextY) == true)
            if (visit[nextY][nextX] == false && map[nextY][nextX] != 0)
                dfs(nextX, nextY, visit);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        vector<int> row(M, 0);
        for (int j = 0; j < M; ++j)
            cin >> row[j];
        map.emplace_back(row);
    }

    int answer = 0;
    while (true) {
        int split = 0;
        vector<vector<bool>> visit(N, vector<bool>(M, false));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (visit[i][j] == false && map[i][j] != 0) {
                    ++split;
                    dfs(j, i, visit);
                }
            }
        }
        if (split >= 2)
            break;
        else if (split == 0) {
            answer = 0;
            break;
        }
        melt();
        ++answer;
    }
    cout << answer << endl;
    return 0;
}
