#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cnt;
    cin >> cnt;
    
    vector<int> arr(cnt, 0);
    for (int i = 0; i < cnt; ++i)
        cin >> arr[i];
    
    int target;
    cin >> target;
    
    sort(arr.begin(), arr.end());
    
    int answer = 0;
    int head = 0, tail = arr.size() - 1;
    while (head < tail) {
        int sum = arr[head] + arr[tail];
        if (sum == target) {
            ++answer;
            ++head;
        }
        else if (sum > target)
            --tail;
        else if (sum < target)
            ++head;
    }
    cout << answer << "\n";
    return 0;
}
