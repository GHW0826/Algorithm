class Solution {
public:
    int dx[4] = { -1,  0,  1,  0 };
    int dy[4] = { 0, -1,  0,  1 };
    vector<vector<bool>> visit;

    bool InvalidPos(vector<vector<char>>& grid, int x, int y)
    {
        return !(x < 0 || x > grid[0].size() - 1 || y < 0 || y > grid.size() - 1);
    }

    int visit_lands(vector<vector<char>>& grid, int x, int y)
    {
        visit[y][x] = true;
        for (int dir = 0; dir < 4; ++dir) {
            int next_x = x + dx[dir];
            int next_y = y + dy[dir];
            if (InvalidPos(grid, next_x, next_y) == true)
                if (visit[next_y][next_x] == false && grid[next_y][next_x] == '1')
                    visit_lands(grid, next_x, next_y);
        }
        return 0;
    }


    int numIslands(vector<vector<char>> grid)
    {
        visit.resize(grid.size(), vector<bool>(grid[0].size(), false));

        int answer = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (InvalidPos(grid, j, i) == true) {
                    if (visit[i][j] == false && grid[i][j] == '1') {
                        visit_lands(grid, j, i);
                        ++answer;
                    }
                }
            }
        }

        return answer;
    }
};
