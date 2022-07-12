#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() <= 1)
        return { -1 };
    
    auto iter = min_element(arr.begin(), arr.end());
    arr.erase(iter);
    return arr;
}
