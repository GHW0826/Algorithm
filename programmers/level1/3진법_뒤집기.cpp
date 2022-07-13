#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n) {
    string ternary;
    while (n > 0) {
        ternary += to_string(n % 3);
        n /= 3;
    }
    reverse(ternary.begin(), ternary.end());
    int answer = 0;
    for (int i = 0; i < ternary.size(); ++i)
        answer += (ternary[i] - '0') * pow(3, i);
    return answer;
}
