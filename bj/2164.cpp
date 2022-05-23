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
    
    queue<int> q;
    for (int i = 1; i <= cnt; ++i)
        q.push(i);
    
    while (q.size() > 1) {
        q.pop();
        int top = q.front();
        q.pop();
        q.push(top);
    }
    cout << q.front() << "\n";
    return 0;
}
