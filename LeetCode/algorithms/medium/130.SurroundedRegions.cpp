class Solution {
public:

    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    int col;
    int row;
    vector<vector<bool>> visit;

    bool isInMap(int x, int y) {
        return (x < 0 || x >= col || y < 0 || y >= row) == false;
    }

    void bfs(vector<vector<char>>& board, int x, int y) {

        visit[y][x] = true;
        board[y][x] = 'K';

        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (isInMap(nextX, nextY) == false)
                continue;
            if (visit[nextY][nextX] == true)
                continue;

            if (board[nextY][nextX] == 'O') {
                visit[nextY][nextX] = true;
                board[nextY][nextX] = 'K';
                bfs(board, nextX, nextY);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        col = board[0].size();
        row = board.size();
        visit.resize(row, vector<bool>(col, false));
        // top
        for (int i = 0; i < board[0].size(); ++i)
            if (board[0][i] == 'O')
                if (visit[0][i] == false)
                    bfs(board, i, 0);

        // left
        for (int i = 0; i < board.size(); ++i)
            if (board[i][0] == 'O')
                if (visit[i][0] == false)
                    bfs(board, 0, i);
        // right
        for (int i = 0; i < board.size(); ++i)
            if (board[i][col - 1] == 'O')
                if (visit[i][col - 1] == false)
                    bfs(board, col - 1, i);
        // bottom
        for (int i = 0; i < board[0].size(); ++i)
            if (board[row - 1][i] == 'O')
                if (visit[row - 1][i] == false)
                    bfs(board, i, row - 1);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'K')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
