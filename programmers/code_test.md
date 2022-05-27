  - 12891
```cpp
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
    int N;
	cin >> N;
    
    vector<int> arr.resize(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
    stack<int> s;
    vector<int> answer.resize(N, -1);
	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i])
			s.pop();
        
		if (s.empty() == false)
            ans[i] = s.top();

		s.push(arr[i]);
	}
	
    for (const auto& it : answer)
        cout << it << " ";
    return 0;
}
```

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

  - 2164
```cpp
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
```

  - 11286
```cpp
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
```
