#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int max_size = max(participant.size(), completion.size());
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < max_size; ++i) {
        if (participant[i] != completion[i]) {
            if (participant.size() > completion.size())
                answer = participant[i];
            else
                answer = completion[i];
            break;
        }
    }
    
    return answer;
}
