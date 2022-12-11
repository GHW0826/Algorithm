#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int period;
    int price;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<Job> jobList(N, Job());
    vector<int> dp(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> jobList[i].period >> jobList[i].price;

    for (int i = N - 1; i >= 0; --i) {
        int way = 0;
        if (i + jobList[i].period <= N - 1)
            way += dp[i + jobList[i].period];
        if (jobList[i].period <= N - i)
            way += jobList[i].price;
        if (i == N - 1)
            dp[i] = way;
        else
            dp[i] = max(way, dp[i + 1]);
    }

    cout << dp[0] << endl;

    return 0;
}
