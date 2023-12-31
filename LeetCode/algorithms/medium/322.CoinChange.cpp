#include <vector>
#include <climits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        // dp[i]가 i를 만들기 위한 경우의 수
        // dp[1] = 1을 만들기 위한 경우의
        // dp[i] , do[0] + 1
        for (int coin : coins)
            for (int i = coin; i <= amount; ++i)
                dp[i] = std::min(dp[i], dp[i - coin] + 1);

        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};
