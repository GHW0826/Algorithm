#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    map<string, string> table_;
    table_["zero"]  = "0"; table_["one"]    = "1"; table_["two"]    = "2";
    table_["three"] = "3"; table_["four"]   = "4"; table_["five"]   = "5";
    table_["six"]   = "6"; table_["seven"]  = "7"; table_["eight"]  = "8";
    table_["nine"]  = "9";

    string answer, word;
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i]))
            answer += s[i];
        else
            word += s[i];

        if (table_.find(word) != table_.end()) {
            answer += table_[word];
            word = "";
        }
    }
    return atoi(answer.c_str());
}
