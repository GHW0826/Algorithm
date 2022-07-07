#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int>::const_iterator begin = array.begin();
    vector<int>::const_iterator end = array.end();
    for (const auto& it : commands) {
        begin = array.begin() + it[0] - 1;
        end = array.begin() + it[1];

        vector<int> sub(begin, end);
        std::sort(sub.begin(), sub.end());
        answer.push_back(sub[it[2] - 1]);
    }

    return answer;
}
