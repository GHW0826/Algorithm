#include <vector>
using namespace std;

double solution(vector<int> arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i)
        sum += arr[i];
    double answer = static_cast<double>(sum) / arr.size();
    return answer;
}
