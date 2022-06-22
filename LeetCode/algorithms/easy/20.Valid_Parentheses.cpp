class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_;
        string open = "([{", close = ")]}";
        for (int i = 0; i < s.size(); ++i) {
            if (find(open.begin(), open.end(), s[i]) != open.end())
                stack_.push(s[i]);
            else {
                if (stack_.empty() == true)
                    return false;
                
                int idx = close.find(s[i]);
                if (open[idx] != stack_.top())
                    return false;
                
                stack_.pop();
            }
        }
        return stack_.empty() == true;
    }
};
