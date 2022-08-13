#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    for (int i = 0; i < answer.size(); ++i) {
        int price = prices[i];
        for (int j = i + 1; j < prices.size(); ++j) {
            ++answer[i];
            if (price > prices[j])
                break;
        }
    }
    return answer;
}
