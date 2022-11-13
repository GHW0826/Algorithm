#include <string>
#include <vector>
#include <set>
using namespace std;

int dx[4] = { 0, 1, 0, 1 };
int dy[4] = { 0, 0, 1, 1 };
int row;
int col;

vector<string> map;
set<pair<int, int>> pos;
int answer = 0;

bool isInMap(int x, int y) {
    return (x < 0 || x >= col || y < 0 || y >= row) == false;
}


void down() {
    for (int i = 0; i < col; ++i) {
        vector<int> rowWord;
        for (int j = row - 1; j >= 0; --j)
            if (map[j][i] != '0')
                rowWord.push_back(map[j][i]);
        if (rowWord.size() > 0) {
            int k = 0;
            for (int j = row - 1; j >= 0; --j) {
                if (k < rowWord.size())
                    map[j][i] = rowWord[k++];
                else
                    map[j][i] = '0';
            }
        }
    }
}

void process() {
    bool first = true;
    while (first == true || pos.size() > 0) {
        pos.clear();

        for (int i = 0; i < col - 1; ++i) {
            for (int j = 0; j < row - 1; ++j) {
                if (map[j][i] == map[j][i + 1] &&
                    map[j + 1][i + 1] == map[j][i + 1] &&
                    map[j + 1][i + 1] == map[j + 1][i] &&
                    map[j][i] != '0') {
                    pos.insert(make_pair(j, i));
                    pos.insert(make_pair(j, i + 1));
                    pos.insert(make_pair(j + 1, i));
                    pos.insert(make_pair(j + 1, i + 1));
                }
            }
        }

        for (const auto& it : pos)
            map[it.first][it.second] = '0';

        down();

        answer += pos.size();
        first = false;
    }
}


int solution(int m, int n, vector<string> board) {
    row = m;
    col = n;
    map = board;
    process();

    return answer;
}
