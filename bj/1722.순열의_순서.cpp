#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    vector<bool> check(21, false);
    vector<long long> fact(21, 1);
    for (int i = 1; i < 21; ++i)
        fact[i] = fact[i - 1] * i;

    int type;
    cin >> type;
    if (type == 1) {
        long long num = 0;
        cin >> num;

        vector<int> arr(N, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (check[j] == true)
                    continue;
                if (num > fact[N - i - 1])
                    num -= fact[N - i - 1];
                else {
                    arr[i] = j;
                    check[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < N; ++i)
            cout << arr[i] << " ";
    }
    else {
        vector<int> arr(N, 0);
        for (int i = 0; i < N; ++i)
            cin >> arr[i];

        long long result = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < arr[i]; ++j) {
                if (check[j] == true)
                    continue;

                result += fact[N - 1 - i];
            }
            check[arr[i]] = true;
        }

        cout << result + 1;
    }

    return 0;
}
