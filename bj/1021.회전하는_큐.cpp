#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    deque<int> d;
    for (int i = 1; i <= N; ++i)
        d.push_back(i);

    int answer = 0;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        auto it = find(d.begin(), d.end(), num);
        auto dist = distance(d.begin(), it);
        if (dist <= d.size() / 2) {
            for (int j = 0; j < dist; ++j) {
                int val = d.front();
                d.pop_front();
                d.push_back(val);
            }
            d.pop_front();
        }
        else {
            dist = d.size() - dist;
            for (int j = 0; j < dist; ++j) {
                int val = d.back();
                d.pop_back();
                d.push_front(val);
            }
            d.pop_front();
        }
        answer += dist;
    }
    cout << answer << endl;

    return 0;
}
