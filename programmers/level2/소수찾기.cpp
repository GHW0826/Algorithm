#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

vector<bool> visit;
set<int> nums;
string tmp;

bool isPrime(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0)
            return false;
    return true;
}

void dfs(int num, string& numbers) {
    if (num == numbers.size())
        return;
    for (int i = 0; i < numbers.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            tmp.push_back(numbers[i]);
            nums.insert(stoi(tmp));
            dfs(num + 1, numbers);
            visit[i] = false;
            tmp.pop_back();
        }
    }
}

int solution(string numbers) {

    int answer = 0;
    visit.resize(numbers.size(), false);
    dfs(0, numbers);
    for (const auto& it : nums)
        if (isPrime(it) == true)
            ++answer;

    return answer;
}
