#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int place;
    cin >> place;

    vector<long> places(place);
    for (int i = 0; i < place; ++i)
        cin >> places[i];
    long main, sub;
    cin >> main >> sub;

    long answer = 0;
    for (int i = 0; i < place; ++i) {
        ++answer;
        places[i] -= main;
        if (places[i] > 0) {
            answer += (places[i] / sub);
            if ((places[i] % sub) > 0)
                ++answer;
        }
    }

    cout << answer << "\n";
    return 0;
}
