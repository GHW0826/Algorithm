#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt = 0, armor = 0;
    cin >> cnt;
    cin >> armor;

    int src;
    vector<int> srcs;
    vector<bool> visit;
    for (int i = 0; i < cnt; ++i) {
        cin >> src;
        srcs.push_back(src);
        visit.push_back(false);
    }
    sort(srcs.begin(), srcs.end());

    int answer = 0;
    for (int i = 0; i < cnt; ++i) {
        for (int j = cnt - 1; j > i; --j) {
            if ((srcs[i] + srcs[j] == armor) && visit[j] == false) {
                ++answer;
                visit[j] = true;
                break;
            }
        }
    }
    cout << answer << endl;
    return 0;
}
