#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums) {
    set<int> cnt;
    for (int i = 0; i < nums.size(); ++i)
        cnt.insert(nums[i]);
    
    int sum = 0;
    int answer = 0;
    for (const auto& it : cnt) {
        ++sum;
        if (sum <= nums.size() / 2)
            ++answer;
        else
            break;
    }
    
    return answer;
}
