#include <iostream>
#include <vector>
using namespace std;

int N, M;
int answer = 64;

struct pos {
    int x;
    int y;
public:
    pos(int x, int y) : x(x), y(y) {}
};
vector<pos> cam;

void upSight(pos camPos, vector<vector<int>>& map) {
    for (int i = camPos.y - 1; i >= 0; --i) {
        if (map[i][camPos.x] == 6)
            break;
        if (map[i][camPos.x] == 0)
            map[i][camPos.x] = 7;
        else
            continue;
    }
}

void rightSight(pos camPos, vector<vector<int>>& map) {
    for (int i = camPos.x + 1; i < M; ++i) {
        if (map[camPos.y][i] == 6)
            break;
        if (map[camPos.y][i] == 0)
            map[camPos.y][i] = 7;
        else 
            continue;
    }
}

void downSight(pos camPos, vector<vector<int>>& map) {
    for (int i = camPos.y + 1; i < N; ++i) {
        if (map[i][camPos.x] == 6)
            break;
        if (map[i][camPos.x] == 0)
            map[i][camPos.x] = 7;
        else
            continue;
    }
}

void leftSight(pos camPos, vector<vector<int>>& map) {
    for (int i = camPos.x - 1; i >= 0; --i) {
        if (map[camPos.y][i] == 6)
            break;
        if (map[camPos.y][i] == 0)
            map[camPos.y][i] = 7;
        else 
            continue;
    }
}

void view(int dir, pos pos, vector<vector<int>>& map) {

    if (dir == 0) {
        if (map[pos.y][pos.x] == 1) {
            upSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 2) {
            leftSight(pos, map);
            rightSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 3) {
            upSight(pos, map);
            rightSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 4) {
            leftSight(pos, map);
            upSight(pos, map);
            rightSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 5) {
            upSight(pos, map);
            rightSight(pos, map);
            downSight(pos, map);
            leftSight(pos, map);
        }
    }
    else if (dir == 1) {
        if (map[pos.y][pos.x] == 1) {
            rightSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 2) {
            upSight(pos, map);
            downSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 3) {
            rightSight(pos, map);
            downSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 4) {
            upSight(pos, map);
            rightSight(pos, map);
            downSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 5) {
            upSight(pos, map);
            rightSight(pos, map);
            downSight(pos, map);
            leftSight(pos, map);
        }
    }
    else if (dir == 2) {
        if (map[pos.y][pos.x] == 1) {
            downSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 2) {
            leftSight(pos, map);
            rightSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 3) {
            downSight(pos, map);
            leftSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 4) {
            leftSight(pos, map);
            rightSight(pos, map);
            downSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 5) {
            upSight(pos, map);
            rightSight(pos, map);
            downSight(pos, map);
            leftSight(pos, map);
        }
    }
    else if (dir == 3) {
        if (map[pos.y][pos.x] == 1) {
            leftSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 2) {
            upSight(pos, map);
            downSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 3) {
            leftSight(pos, map);
            upSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 4) {
            leftSight(pos, map);
            upSight(pos, map);
            downSight(pos, map);
        }
        else if (map[pos.y][pos.x] == 5) {
            upSight(pos, map);
            rightSight(pos, map);
            downSight(pos, map);
            leftSight(pos, map);
        }
    }
}

void dfs(int depth, int dir, vector<vector<int>>& map) {

    if (depth == cam.size()) {
        int noSee = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (map[i][j] == 0)
                    ++noSee;
        answer = min(answer, noSee);
        return;
    }

    view(dir, cam[depth], map);

    for (int i = 0; i < 4; ++i) {
        vector<vector<int>> copy = map;
        dfs(depth + 1, i, copy);
    }
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
            if (1 <= map[i][j] && map[i][j] <= 5)
                cam.push_back(pos(j, i));
        }
    }

    // dir
    if (cam.size() > 0) {
        for (int i = 0; i < 4; ++i) {
            vector<vector<int>> copy = map;
            dfs(0, i, copy);
        }
    }
    else {
        int noSee = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (map[i][j] == 0)
                    ++noSee;
        answer = min(answer, noSee);
    }

    cout << answer << endl;

    return 0;
}
