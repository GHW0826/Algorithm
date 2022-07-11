#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> s;
    int answer = 0;
    for (int i = 0; i < moves.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            int& value = board[j][moves[i] - 1];
            if (value != 0) {
                if (s.empty() == true)
                    s.push(value);
                else {
                    if (s.top() != value)
                        s.push(value);
                    else {
                        s.pop();
                        answer += 2;
                    }
                }
                value = 0;
                break;
            }
        }
    }
    return answer;
}
