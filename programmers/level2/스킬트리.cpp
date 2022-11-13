#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); ++i) {
        int pos = 0;
        bool flag = true;
        for (int j = 0; j < skill_trees[i].size(); ++j) {
            int pos2 = find(skill.begin(), skill.end(), skill_trees[i][j]) - skill.begin();
            if (pos2 == pos)
                ++pos;
            else if (pos2 == skill.size())
                continue;
            else {
                flag = false;
                break;
            }
        }
        if (flag == true)
            ++answer;
    }
    return answer;
}
