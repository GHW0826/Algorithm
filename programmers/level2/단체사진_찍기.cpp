#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    vector<char> order = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    vector<tuple<string, char, int>> condition;
    for (int i = 0; i < data.size(); ++i)
        condition.emplace_back(make_tuple(data[i].substr(0, 3), data[i][3], data[i][4] - '0'));


    int answer = 0;
    do {
        bool pass = true;
        for (int i = 0; i < condition.size(); ++i) {
            auto it1 = find(order.begin(), order.end(), get<0>(condition[i])[0]);
            auto it2 = find(order.begin(), order.end(), get<0>(condition[i])[2]);
            int dist1 = distance(order.begin(), it1);
            int dist2 = distance(order.begin(), it2);
            int dist = abs(dist1 - dist2) - 1;
            
            if (get<1>(condition[i]) == '=') {
                if (dist != get<2>(condition[i]))
                    pass = false;
            }
            else if (get<1>(condition[i]) == '>') {
                if (dist <= get<2>(condition[i]))
                    pass = false;
            }
            else if (get<1>(condition[i]) == '<') {
                if (dist >= get<2>(condition[i]))
                    pass = false;
            }
        }
        if (pass == true)
            ++answer;
    } while (next_permutation(order.begin(), order.end()));
    return answer;
}
