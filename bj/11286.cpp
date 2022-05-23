#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt;
    cin >> cnt;

    int command;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < cnt; ++i) {
        cin >> command;
        if (command == 0) {
            if (pq.empty() == false) {
                auto elem = pq.top();
                pq.pop();
                cout << elem.second << "\n";
            }
            else
                cout << "0\n";
        }
        else
            pq.push(make_pair(abs(command), command));
    }

    return 0;
}
