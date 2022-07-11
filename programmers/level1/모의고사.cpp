#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    int size = answers.size();
    vector<int> correct(3, 0);
    vector<int> way1 = { 1,2,3,4,5 };
    vector<int> way2 = { 2,1,2,3,2,4,2,5 };
    vector<int> way3 = { 3,3,1,1,2,2,4,4,5,5 };
    for (int i = 0; i < size; ++i) {
        if (answers[i] == way1[i % 5])
            ++correct[0];
        if (answers[i] == way2[i % 8])
            ++correct[1];
        if (answers[i] == way3[i % 10])
            ++correct[2];
    }

    vector<int> answer;
    int max = *max_element(correct.begin(), correct.end());
    if (max == 0)
        return {};
    
    for (int i = 0; i < 3; ++i)
        if (correct[i] == max)
            answer.push_back(i + 1);
    return answer;
}
