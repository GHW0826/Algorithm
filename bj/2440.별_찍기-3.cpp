#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cnt;
    cin >> cnt;
    
    for (int i = 0; i < cnt; ++i) {
        for (int j = i; j < cnt; ++j)
            cout << "*";
        for (int j = cnt - i; j < cnt; ++j)
            cout << "";
        cout << "\n";
    }
    
    return 0;
}
