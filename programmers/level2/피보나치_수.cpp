#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    vector<long long> pibo(n + 1, 0);
    pibo[0] = 0;
    pibo[1] = 1;
    for (long long i = 2; i <= n; ++i)
        pibo[i] = (pibo[i - 1] + pibo[i - 2]) % 1234567;
    return pibo[n] % 1234567;
}
