#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long G;
    cin >> G;
    long long cur = 1, post = 1;

    bool answer = false;
    while (true) {
        if ((pow(cur, 2) - pow(post, 2)) == G) {
            answer = true;
            cout << cur << endl;
        }
        if ((pow(cur, 2) - pow(post, 2)) < G)
            ++cur;
        else
            ++post;
        if (cur <= post)
            break;
    }
    if (answer == false)
        cout << -1 << endl;
    return 0;
}
