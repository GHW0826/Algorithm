#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int N, K;
int s, answerX, answerY;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct info {
    int val;
    int x;
    int y;
public:
    info(int val, int x, int y) : val(val), x(x), y(y) {}
    bool operator< (const info& item) const {
        return val < item.val;
    }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    
    vector<info> vir;
    vector<vector<int>> map(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if (0 < map[i][j])
                vir.push_back(info(map[i][j], j, i));
        }
    }
    cin >> s >> answerX >> answerY;

    sort(vir.begin(), vir.end());
    int cnt = 0;
    while (cnt < s) {
        int virCnt = vir.size();
        for (int i = 0; i < virCnt; ++i) {
            int val = vir[i].val;
            int x = vir[i].x;
            int y = vir[i].y;

            for (int i = 0; i < 4; ++i) {
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                if ((nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) == true)
                    continue;
                if (map[nextY][nextX] != 0)
                    continue;

                map[nextY][nextX] = val;
                vir.push_back(info(val, nextX, nextY));
            }
        }
        if (map[answerX - 1][answerY - 1] > 0)
            break;
        ++cnt;
    }

    cout << map[answerX - 1][answerY - 1] << endl;

    return 0;
}
