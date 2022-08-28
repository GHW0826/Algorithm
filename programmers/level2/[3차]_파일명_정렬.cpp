#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> files) {
    set<tuple<string, int, int>> order;
    string tail;
    for (int i = 0; i < files.size(); ++i) {
        size_t lastHeadIndex = files[i].find_first_of("0123456789");
        string head = files[i].substr(0, lastHeadIndex);
        tail = files[i].substr(lastHeadIndex, files[i].size());

        size_t lastNumberIndex = tail.find_first_not_of("0123456789");
        string number = tail.substr(0, lastNumberIndex);
        if (lastNumberIndex < files[i].size())
            tail = tail.substr(lastNumberIndex, files[i].size());

        std::transform(head.begin(), head.end(), head.begin(), ::tolower);
        order.insert(make_tuple(head, atol(number.c_str()), i));
    }

    vector<string> answer;
    for (const auto& it : order) 
        answer.push_back(files[get<2>(it)]);
    return answer;
}
