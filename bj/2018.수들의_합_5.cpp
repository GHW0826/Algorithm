#include <iostream> 
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num = 0;
    cin >> num;

    int answer = 1;
    for (int i = 1; i < num; ++i) {
        int sum = 0;
        sum += i;
        for (int j = i + 1; j < num; ++j) {
            sum += j;
            if (sum > num)
                break;
            else if (sum == num)
                ++answer;
        }
    }
    cout << answer << endl;
    return 0;
}
