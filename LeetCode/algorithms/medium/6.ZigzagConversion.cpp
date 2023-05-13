#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        vector<vector<char>> container(numRows, vector<char>());

        bool dir = true;
        int row = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (dir == true) {
                container[row].push_back(s[i]);
                ++row;
            }
            else {
                --row;
                container[row].push_back(s[i]);
            }

            if (row == numRows) {
                dir = false;
                --row;
            }
            else if (row == 0) {
                dir = true;
                ++row;
            }
        }
        std::ostringstream out;
        for (int i = 0; i < container.size(); ++i)
            for (int j = 0; j < container[i].size(); ++j)
                out << container[i][j];

        string answer(out.str());
        return answer;
    }
};
