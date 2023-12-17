#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(), data.end(), [&](auto& litem, auto& ritem) {
            if (litem[col - 1] != ritem[col - 1])
                return litem[col - 1] < ritem[col - 1];
            return litem[0] > ritem[0];
        });

    int answer = 0;
    for (int i = row_begin - 1; i <= row_end - 1; ++i) {
        int sum = 0;
        for (int j = 0; j < data[i].size(); ++j) {
            sum += data[i][j] % (i + 1);
        }
        answer = answer ^ sum;
    }


    return answer;
}
