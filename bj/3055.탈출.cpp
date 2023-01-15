#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int row, col;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct pos {
    int x;
    int y;
    int step;
public:
    pos(int x, int y, int step) : x(x), y(y), step(step) {}
};

struct hedgehog {
    int x;
    int y;
    int dist;
public:
    hedgehog(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool isInMap(int x, int y) {
    return (x < 0 || x >= col || y < 0 || y >= row) == false;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col;

    queue<hedgehog> q;
    queue<pos> waterPos;
    vector<vector<bool>> visit(row, vector<bool>(col, false));
    vector<vector<bool>> waterVisit(row, vector<bool>(col, false));
    vector<vector<char>> map(row, vector<char>(col));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> map[i][j];
            if (map[i][j] == '*')
                waterPos.push(pos(j, i, 0));
            else if (map[i][j] == 'S') {
                q.push(hedgehog(j, i, 0));
                visit[i][j] = true;
            }
        }
    }

    int answer = 5000;
    while (q.empty() == false) {
       
        int waterStep = waterPos.front().step;
        while (waterPos.empty() == false && waterPos.front().step == waterStep) {
            int waterX = waterPos.front().x;
            int waterY = waterPos.front().y;
            waterPos.pop();

            for (int i = 0; i < 4; ++i) {
                int nextX = waterX + dx[i];
                int nextY = waterY + dy[i];
                if (isInMap(nextX, nextY) == true) {
                    if (waterVisit[nextY][nextX] == false) {
                        if (map[nextY][nextX] == '.' ||
                            map[nextY][nextX] == 'S') {
                            waterPos.push(pos(nextX, nextY, waterStep + 1));
                            waterVisit[nextY][nextX] = true;
                            map[nextY][nextX] = '*';
                        }
                    }
                }
            }
        }

        int dist = q.front().dist;
        while (q.empty() == false && q.front().dist == dist) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                if (isInMap(nextX, nextY) == true) {
                    if (visit[nextY][nextX] == false) {
                        if (map[nextY][nextX] == '.') {
                            q.push(hedgehog(nextX, nextY, dist + 1));
                            map[nextY][nextX] = 'S';
                            visit[nextY][nextX] = true;
                        }
                        else if (map[nextY][nextX] == 'D')
                            if (answer > dist + 1)
                                answer = dist + 1;
                    }
                }
            }
        }

    }

    if (answer == 5000)
        cout << "KAKTUS" << endl;
    else
        cout << answer << endl;


    return 0;
}
