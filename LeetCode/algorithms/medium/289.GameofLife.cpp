class Solution {
public:
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int row = 0;
    int col = 0;
    bool isInBoard(int x, int y) {
        return (x < 0 || x >= col || y < 0 || y >= row) == false;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> answer(board);

        row = board.size();
        col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int cnt = 0;
                for (int dir = 0; dir < 8; dir++) {
                    int nextX = j + dx[dir];
                    int nextY = i + dy[dir];
                    if (isInBoard(nextX, nextY) == false)
                        continue;
                    if (board[nextY][nextX] == 1)
                        ++cnt;
                }

                if (board[i][j] == 1 && cnt < 2)
                    answer[i][j] = 0;
                else if (board[i][j] == 1 && (cnt == 2 || cnt == 3)) 
                    answer[i][j] = 1;
                else if (board[i][j] == 0 && cnt == 3) 
                    answer[i][j] = 1;
                else if (board[i][j] == 1 && cnt > 3) 
                    answer[i][j] = 0;
            }
        }

        board = answer;
    }
};
