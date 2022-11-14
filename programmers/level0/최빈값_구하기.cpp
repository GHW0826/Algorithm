#include <vector>
#include <map>
using namespace std;

int solution(vector<int> array) {
    map<int, int> table;
    for (int i = 0; i < array.size(); ++i)
        table[array[i]]++;
    
    int answer = 0, maxCnt = 0;
    for (const auto& it : table) {
        if (maxCnt == it.second)
            answer = -1;
        else if (maxCnt < it.second) {
            answer = it.first;
            maxCnt = it.second;
        }
    }
    return answer;
}
