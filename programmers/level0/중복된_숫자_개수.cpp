#include <vector>
using namespace std;

int solution(vector<int> array, int n) {
    vector<int> cnt(101, 0);
    for (int i = 0; i < array.size(); ++i)
        ++cnt[array[i]];
    return cnt[n];
}
