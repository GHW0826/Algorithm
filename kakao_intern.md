
숫자 문자열과 영단어
  - cpp
```cpp
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    map<string, string> table_;
    table_["zero"]  = "0"; table_["one"]    = "1"; table_["two"]    = "2";
    table_["three"] = "3"; table_["four"]   = "4"; table_["five"]   = "5";
    table_["six"]   = "6"; table_["seven"]  = "7"; table_["eight"]  = "8";
    table_["nine"]  = "9";

    string answer, word;
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i]))
            answer += s[i];
        else
            word += s[i];

        if (table_.find(word) != table_.end()) {
            answer += table_[word];
            word = "";
        }
    }
    return atoi(answer.c_str());
}

```


거리두기 확인하기

```cpp
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int infection_prevention_check(vector<pair<int, int>>& pos, vector<pair<int, int>>& tables) 
{
    for (int j = 0; j < pos.size() - 1; ++j) {
        int dist = 0;
        for (int k = j + 1; k < pos.size(); ++k) {
            dist = abs(pos[k].first - pos[j].first) + abs(pos[k].second - pos[j].second);

            if (dist < 2)
                return 0;
            else if (dist <= 2) {
                auto it = find_if(tables.begin(), tables.end(), [&](auto& elem) {
                    int x_min = min(pos[j].first, pos[k].first);
                    int x_max = max(pos[j].first, pos[k].first);
                    int y_min = min(pos[j].second, pos[k].second);
                    int y_max = max(pos[j].second, pos[k].second);

                    return (x_min <= elem.first && elem.first <= x_max) &&
                        (y_min <= elem.second && elem.second <= y_max);
                    });
                if (it != tables.end())
                    return 0;
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int maps = places.size();
    int rows = places[0].size();
    for (int i = 0; i < maps; ++i) {
        vector<pair<int, int>> pos;
        vector<pair<int, int>> tables;

        for (int j = 0; j < rows; ++j) {
            for (int k = 0; k < places[i][j].size(); ++k) {
                if (places[i][j][k] == 'P')
                    pos.emplace_back(make_pair(j, k));
                else if (places[i][j][k] == 'O')
                    tables.emplace_back(make_pair(j, k));
            }
        }

        if (pos.size() == 0) {
            answer.push_back(1);
            continue;
        }

        answer.push_back(infection_prevention_check(pos, tables));
    }
    return answer;
}
```



표 편집
```cpp
// 1. time limit
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    
    set<int> table;
    stack<int> undo;

    for (int i = 0; i < n; ++i)
        table.insert(i);

    auto it = table.begin();
    advance(it, k);
    for (int i = 0; i < cmd.size(); ++i) {
        if (cmd[i][0] == 'C') {
            undo.push(*it);
            it = table.erase(it);
            if (it == table.end())
                advance(it, -1);
        }
        else if (cmd[i][0] == 'Z') {
            int recover = undo.top();
            undo.pop();
            table.insert(recover);
        }
        else {
            int move = atoi(cmd[i].substr(2, cmd[i].size()).c_str());

            if (cmd[i][0] == 'U')
                advance(it, -move);
            else if (cmd[i][0] == 'D')
                advance(it, move);
        }
    }
    string answer = "";
    for (int i = 0; i < n; ++i) {
        if (table.find(i) != table.end())
            answer += "O";
        else
            answer += "X";
    }
    return answer;
}
```
