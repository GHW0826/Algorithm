#include <queue>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool isInMap(int x, int y, int row, int col) {
    return (x < 0 || x >= col || y < 0 || y >= row) == false;
}


void dfs(vector<string>& pic, vector<vector<bool>>& visit, int col, int row, int size, char color) {

    for (int k = 0; k < 4; ++k) {
        int nextX = col + dx[k];
        int nextY = row + dy[k];
        if (isInMap(nextX, nextY, size, size) == true) {
            if (visit[nextY][nextX] == false && pic[nextY][nextX] == color) {
                visit[nextY][nextX] = true;
                dfs(pic, visit, nextX, nextY, size, pic[nextY][nextX]);
            }
        }
    }
}

void process(vector<string>& pic, vector<vector<bool>>& visit, int size, int& answer) {
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (isInMap(col, row, size, size) == true && visit[row][col] == false) {
                visit[row][col] = true;
                dfs(pic, visit, col, row, size, pic[row][col]);
                ++answer;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int size = 0;
    cin >> size;

    vector<string> pic;
    vector<string> daltonism_pic;
    vector<vector<bool>> visit_pic(size, vector<bool>(size, false));
    vector<vector<bool>> visit_daltonism_pic(size, vector<bool>(size, false));
    for (int i = 0; i < size; ++i) {
        string row;
        cin >> row;
        pic.emplace_back(row);
        for (int j = 0; j < size; ++j)
            if (row[j] == 'G')
                row[j] = 'R';
        daltonism_pic.emplace_back(row);
    }

    int answer1 = 0, answer2 = 0;
    process(pic, visit_pic, size, answer1);
    process(daltonism_pic, visit_daltonism_pic, size, answer2);

    cout << answer1 << " " << answer2 << endl;
    return 0;
}
