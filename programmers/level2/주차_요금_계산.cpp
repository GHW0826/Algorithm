#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <map>
#include <cmath>
using namespace std;

int last_time = 23 * 60 + 59;
vector<int> solution(vector<int> fees, vector<string> records) {
    int baseTime = fees[0], basePee = fees[1], unitTime = fees[2], unitPee = fees[3];
    vector<vector<string>> parse;
    for (int i = 0; i < records.size(); ++i) {
        vector<string> lines;
        istringstream ss(records[i]);
        string stringBuffer;
        while (getline(ss, stringBuffer, ' '))
            lines.push_back(stringBuffer);
        parse.emplace_back(lines);
    }
    
    map<string, int> time_acc;
    map<string, int> time_cnt;
    for (int i = 0; i < parse.size(); ++i) {
        string t = parse[i][0];
        int time = atoi(t.substr(0, 2).c_str()) * 60 + atoi(t.substr(3, 4).c_str());
        time_cnt[parse[i][1]] += (parse[i][2] == "IN") ? -1 : 1;
        time_acc[parse[i][1]] += ((parse[i][2] == "IN") ? -1 : 1) * time;
    }

    for (const auto& it : time_cnt)
        if (it.second != 0)
            time_acc[it.first] += last_time;

    vector<int> answer;
    for (const auto& it : time_acc)
        answer.push_back(basePee + ceil(max((it.second - baseTime) / (double)unitTime, 0.0)) * unitPee);
    return answer;
}
