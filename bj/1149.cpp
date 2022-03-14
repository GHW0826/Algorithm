#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

// [r, g, b]
int dp[1001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    
    int caseNum = 0;
    cin >> caseNum;
    for (int i = 1; i <= caseNum; ++i) {
        int r = 0, g = 0, b = 0;
        cin >> r >> g >> b;
        
        dp[i][0] = r + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = g + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = b + min(dp[i - 1][0], dp[i - 1][1]);
    }

    int answer = min(dp[caseNum][0], min(dp[caseNum][1], dp[caseNum][2]));
    cout << answer << endl;

    return 0;
} 
