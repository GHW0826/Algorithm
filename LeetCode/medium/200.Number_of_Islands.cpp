class Solution {
public:
    bool InvalidPos(vector<vector<char>>& grid, int x, int y)
    { return !(x < 0 || x > grid[0].size() - 1 || y < 0 || y > grid.size() - 1); }

    bool visitCheck(vector<vector<char>>& grid, vector<vector<bool>>& visit, int x, int y)
    { return (InvalidPos(grid, x, y) == true) && grid[y][x] == '1' && visit[y][x] == false; }

    int visit_lands(vector<vector<char>>& grid, vector<vector<bool>>& visit, int x, int y)
    {
        int dx[4] = { -1, 0, 1, 0 };
        int dy[4] = { 0, -1, 0, 1 };

        grid[y][x] = '0';
        visit[y][x] = true;
        for (int dir = 0; dir < 4; ++dir) {
            int next_x = x + dx[dir];
            int next_y = y + dy[dir];
            if (visitCheck(grid, visit, next_x, next_y) == true)
                visit_lands(grid, visit, next_x, next_y);
        }
        return 0;
    }


    int numIslands(vector<vector<char>>& grid)
    {
        vector<vector<bool>> visit;
        for (int i = 0; i < grid.size(); ++i)
            visit.emplace_back(vector<bool>(grid[0].size(), false));

        int answer = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (visitCheck(grid, visit, j, i) == true) {
                    visit_lands(grid, visit, j, i);
                    ++answer;
                }
            }
        }

        return answer;
    }
};
