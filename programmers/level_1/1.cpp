#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 1. 정렬 비교.
string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int i = 0;
    for (; i < completion.size(); ++i)
        if (participant[i] != completion[i])
            return completion[i];
    
    return participant[i];
}

// 2. 해시
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> table;    
    for (int i = 0; i < completion.size(); ++i)
        table[completion[i]]++;
        
    for (int i = 0; i < participant.size(); ++i) {
        if (--table[participant[i]] < 0) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}
