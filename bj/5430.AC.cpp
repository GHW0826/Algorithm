#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    vector<string> answer;
    for (int i = 0; i < T; ++i) {
        int length;
        string command, arr;
        cin >> command;
        cin >> length;
        cin >> arr;

        int popCnt = count(command.begin(), command.end(), 'D');
        if (length < popCnt) {
            answer.push_back("error");
            continue;
        }

        deque<int> d;
        stringstream ss(arr.substr(1, arr.size() - 2));
        string temp;
        while (getline(ss, temp, ','))
            d.push_back(atoi(temp.c_str()));

        int dir = 1;
        for (int j = 0; j < command.size(); ++j) {
            if (command[j] == 'R')
                dir *= -1;
            else {
                if (dir == 1)
                    d.pop_front();
                else
                    d.pop_back();
            }
        }

        string output("[");
        if (dir == 1) {
            for (int j = 0; j < d.size(); ++j)
                output += to_string(d[j]) + ",";
        }
        else {
            for (int j = d.size() - 1; j >= 0; --j)
                output += to_string(d[j]) + ",";
        }
        if (d.size() > 0)
            output[output.size() - 1] = ']';
        else
            output += ']';

        answer.push_back(output);
    }

    for (const auto& it : answer)
        cout << it << endl;
    return 0;
}
