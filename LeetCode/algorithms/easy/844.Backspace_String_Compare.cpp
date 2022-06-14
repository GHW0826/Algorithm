class Solution {
public:
    string process(string word)
    {
        string answer = "";
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '#') {
                if (answer.size() > 0)
                    answer.pop_back();
            }
            else
                answer += word[i];
        }
        return answer;
    }
    
    bool backspaceCompare(string s, string t) {
        string s_answer = process(s);
        string t_answer = process(t);

        return s_answer == t_answer;
    }
};
