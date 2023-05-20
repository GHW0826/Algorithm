class Solution {
public:
    string reverseWords(string s) {
        vector<string> cotainer;
        std::ostringstream out;
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i]) || isdigit(s[i]))
                out << s[i];
            else {
                if (out.tellp() > 0)
                    cotainer.push_back(out.str());
                out.str("");
            }
        }
        if (out.tellp() > 0)
            cotainer.push_back(out.str());
        std::reverse(cotainer.begin(), cotainer.end());
        string answer = std::accumulate(
            std::next(cotainer.begin()), cotainer.end(), cotainer[0],
            [](std::string a, std::string b) {
                return a + ' ' + b;
            });
        return answer;
    }
};
