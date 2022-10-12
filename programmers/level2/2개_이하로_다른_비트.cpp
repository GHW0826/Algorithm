#include <string>
#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (const auto& it : numbers) {
        if (it % 2 == 0)
            answer.push_back(it + 1);
        else {
            long long bit = 1;
            while (true) {
                if ((it & bit) == 0)
                    break;
                bit *= 2;
            }
            bit /= 2;
            answer.push_back(it + bit);
        }
    }
    return answer;
}
