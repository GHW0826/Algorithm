#include<tuple>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {  0,-1, 0, 1 };

bool isInMap(vector<vector<int>>& map, int x, int y) {
    return !(x < 0 || x >= map[0].size() || y < 0 || y >= map.size());
}

int solution(vector<vector<int>> maps)
{
    int goal_x = maps[0].size() - 1;
    int goal_y = maps.size() - 1;
    
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));
    int answer = -1;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 1));
    visit[0][0] = true;
    while (q.empty() == false) {
        auto val = q.front();
        int cur_x = get<0>(val);
        int cur_y = get<1>(val);
        int dist  = get<2>(val);
        if (cur_x == goal_x && cur_y == goal_y) {
            answer = dist;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if (isInMap(maps, next_x, next_y)) {
                if (maps[next_y][next_x] == 1 && visit[next_y][next_x] == false) {
                    visit[next_y][next_x] = true;
                    q.push(make_tuple(next_x, next_y, dist + 1));
                }
            }
        }
    }
    return answer;
}
