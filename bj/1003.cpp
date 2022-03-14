#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
// 0갯수, 1갯수
int dp[41][2];

int fibo(int x, int index)
{
    if (dp[x][index] == -1) {
        dp[x][0] = fibo(x - 1, 0) + fibo(x - 2, 0);
        dp[x][1] = fibo(x - 1, 1) + fibo(x - 2, 1);
    }

    return dp[x][index];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;

    int num = 0;
    cin >> num;

    int fibo_num = 0;
    vector<int> nums;
    for (int i = 0; i < num; ++i) {
        cin >> fibo_num;
        nums.push_back(fibo_num);
    }
    int max = *max_element(nums.begin(), nums.end());
    fibo(max, 0);

    for (const auto& it : nums)
        cout << dp[it][0] << " " << dp[it][1] << endl;

    return 0;
}
