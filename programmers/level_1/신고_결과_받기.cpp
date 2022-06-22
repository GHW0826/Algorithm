#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, set<string>> table;
    unordered_map<string, set<string>> reports;
    for (int i = 0; i < report.size(); ++i) {
        vector<string> result;
        istringstream iss(report[i]);
        for (string s; iss >> s; )
            result.push_back(s);

        table[result[1]].insert(result[0]);
        reports[result[0]].insert(result[1]);
    }

    vector<int> answer(id_list.size(), 0);
    for (int i = 0; i < id_list.size(); ++i)
        for (auto& it : reports[id_list[i]])
            if (table[it].size() >= k)
                ++answer[i];
    return answer;
}
