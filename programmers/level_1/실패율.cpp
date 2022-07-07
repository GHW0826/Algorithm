#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> stop(N + 1, 0);
    vector<int> reach(N + 1, 0);
    for (int i = 0; i < stages.size(); ++i)
        ++stop[stages[i] - 1];
    for (int i = 0; i < stages.size(); ++i)
        for (int j = 0; j < N; ++j)
            if (stages[i] - 1 >= j)
                ++reach[j];

    set<pair<double, int>> sorted;
    for (int i = 0; i < stop.size(); ++i)
        sorted.insert(make_pair(1 - (stop[i] / static_cast<double>(reach[i])), i + 1));

    vector<int> answer;
    for (const auto& it : sorted)
        if (it.second < N + 1)
            answer.push_back(it.second);

    return answer;
}
