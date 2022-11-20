#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int map_size;

bool isInMap(int x, int y) {
    return (x < 0 || x >= map_size || y < 0 || y >= map_size) == false;
}

class shark
{
public:
    int x;
    int y;
    int size;
    int upgrade;
};

enum Value {
    x = 0,
    y = 1,
    dist = 2
};

vector<vector<int>> InitDist() {
    return vector<vector<int>>(map_size, vector<int>(map_size, -1));
}

void setDistance(shark& baby, vector<vector<int>>& map, vector<vector<int>>& dists) {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(baby.x, baby.y, 0));
    while (q.empty() == false) {
        int x = get<Value::x>(q.front());
        int y = get<Value::y>(q.front());
        int dist = get<Value::dist>(q.front());

        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (isInMap(nextX, nextY) == true) {
                if (map[nextY][nextX] <= baby.size && dists[nextY][nextX] == -1) {
                    dists[nextY][nextX] = dist + 1;
                    q.push(make_tuple(nextX, nextY, dist + 1));
                }
            }
        }
    }
}

pair<int, int> findTarget(shark& baby, vector<vector<int>>& map, vector<vector<int>>& dists) {
    int dist = 500;
    pair<int, int> target(-1, -1);
    for (int i = map_size - 1; i >= 0; --i) {
        for (int j = map_size - 1; j >= 0; --j) {
            if (dists[i][j] != -1 && dists[i][j] <= dist && map[i][j] < baby.size && 0 < map[i][j]) {
                dist = dists[i][j];
                target.first = j;
                target.second = i;
            }
        }
    }
    return target;
}

void eat(shark& baby, pair<int, int>& target, vector<vector<int>>& map) {
     ++baby.upgrade;
    if (baby.upgrade == baby.size) {
        ++baby.size;
        baby.upgrade = 0;
    }
    baby.x = target.first;
    baby.y = target.second;
    map[target.second][target.first] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> map_size;

    shark baby;
    baby.size = 2;
    baby.upgrade = 0;
    vector<vector<int>> map;
    for (int i = 0; i < map_size; ++i) {
        vector<int> row(map_size);
        for (int j = 0; j < map_size; ++j) {
            cin >> row[j];
            if (row[j] == 9) {
                baby.x = j;
                baby.y = i;
                row[j] = 0;
            }
        }
        map.emplace_back(row);
    }
    int answer = 0;
    while (true) {
        auto dists = InitDist();
        setDistance(baby, map, dists);
        auto target = findTarget(baby, map, dists);
        if (target.first != -1) {
            eat(baby, target, map);
            answer += dists[target.second][target.first];
        }
        else
            break;
    }

    cout << answer << endl;

    return 0;
}
