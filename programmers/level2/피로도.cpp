#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> order;
    for (int i = 0; i < dungeons.size(); ++i)
        order.push_back(i);
    
    do {
        int hp = k;
        int load = 0;
        for (int i = 0; i < order.size(); ++i) {
            if (dungeons[order[i]][0] <= hp) {
                ++load;
                hp -= dungeons[order[i]][1];
            }
        }
        answer = max(load, answer);
    } while (next_permutation(order.begin(), order.end()));
    
    return answer;
}
