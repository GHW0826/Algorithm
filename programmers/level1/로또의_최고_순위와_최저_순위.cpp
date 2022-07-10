#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int zero_cnt = 0;
    int win_cnt = 0;
    for (int i = 0; i < lottos.size(); ++i) {
        if (lottos[i] == 0)
            ++zero_cnt;
        else {
            if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
                ++win_cnt;
        }
    }
    int high = min(7 - (win_cnt + zero_cnt), 6);
    int low = min(7 - win_cnt, 6);
    return { high , low };
}
