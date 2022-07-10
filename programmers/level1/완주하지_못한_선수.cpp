#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> table;    
    for (int i = 0; i < completion.size(); ++i)
        ++table[completion[i]];
        
    for (int i = 0; i < participant.size(); ++i) {
        if (--table[participant[i]] < 0) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}
