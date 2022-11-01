#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    for_each(numbers.begin(), numbers.end(), [&](auto& elem) {
        elem *= 2;
    });
    return numbers;
}
