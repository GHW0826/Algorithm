#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    int n;
    vector<string> answer(t, "YES");
    vector<vector<string>> numbers(t);
    for (int i = 0; i < t; ++i) {
        cin >> n;
        
        string number;
        for (int j = 0; j < n; ++j) {
            cin >> number;
            numbers[i].emplace_back(number);
        }
        sort(numbers[i].begin(), numbers[i].end());

        for (int j = 0; j < numbers[i].size() - 1; ++j) {
            if (numbers[i][j] == numbers[i][j + 1].substr(0, numbers[i][j].size())) {
                answer[i] = "NO";
                break;
            }
        }
    }

    for (const auto& it : answer)
        cout << it << "\n";

    return 0;
}
