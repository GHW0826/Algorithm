class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0,-1, 0, 1 };
    const int wall = 10001;

    class pos
    {
    public:
        int x;
        int y;
        int dist;
        pos(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist) {}
    };

    bool isInMap(int x, int y, vector<vector<char>>& map) {
        return (x < 0 || x >= map[0].size() || y < 0 || y >= map.size()) == false;
    }

    int findMinDist(vector<vector<int>>& dist) {
        int answer = 10001;
        int col = dist[0].size();
        int row = dist.size();
        // top
        for (int i = 0; i < col; ++i)
            answer = min(answer, dist[0][i]);

        // bottom
        for (int i = 0; i < col; ++i)
            answer = min(answer, dist[row - 1][i]);

        // left
        for (int i = 0; i < row; ++i)
            answer = min(answer, dist[i][0]);

        // right
        for (int i = 0; i < row; ++i)
            answer = min(answer, dist[i][col - 1]);

        return answer;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> visit(maze.size(), vector<int>(maze[0].size(), wall));

        queue<pos> q;
        q.push(pos(entrance[1], entrance[0], 0));
        while (q.empty() == false) {
            int x = q.front().x;
            int y = q.front().y;
            int dist = q.front().dist;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextX = x + dx[i];
                int nextY = y + dy[i];

                if (isInMap(nextX, nextY, maze) == false)
                    continue;
                if (maze[nextY][nextX] != '.')
                    continue;
                if (visit[nextY][nextX] != wall)
                    continue;
                if (nextX == entrance[1] && nextY == entrance[0])
                    continue;

                q.push(pos(nextX, nextY, dist + 1));
                visit[nextY][nextX] = dist + 1;
            }
        }
        int answer = findMinDist(visit);
        if (answer == wall)
            answer = -1;

        return answer;
    }
}; 
