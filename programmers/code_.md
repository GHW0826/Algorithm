  - 11003
```cpp
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;
	
    deque<pair<int, int>> dq;
	for (int i = 0; i < N; i++) {
		int val;
        cin >> val;
        
		while (dq.empty() == false && dq.back().first > val) 
            dq.pop_back();
		dq.push_back(make_pair(val, i));
        
		while (i - dq.front().second >= L) 
            dq.pop_front();
        cout << dq.front().first;
	}
    
    return 0;
}
```

  - 
