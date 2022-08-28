#include <string>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    if (queue1.empty() == true || queue2.empty() == true)
        return -1;
    long q1Sum = std::accumulate(queue1.begin(), queue1.end(), 0);
    long target = (q1Sum + std::accumulate(queue2.begin(), queue2.end(), 0)) / 2;

    int answer = 0;
    int q1Index = 0, q2Index = 0;
    while (target != q1Sum && q2Index < queue2.size()) {
        if (q1Sum < target) {
            q1Sum += queue2[q2Index];
            queue1.push_back(queue2[q2Index]);
            ++q2Index;
        }
        else if (q1Sum > target) {
            q1Sum -= queue1[q1Index];
            ++q1Index;
        }
        ++answer;
    }
    if (target != q1Sum && q2Index == queue2.size())
        answer = -1;
    return answer;
}
