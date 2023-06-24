class Solution {
public:
    string simplifyPath(string path) {

        stringstream ss(path);
        vector<string> res;
        string token;
        while (getline(ss, token, '/'))
            res.push_back(token);

        stack<string> s;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == "..")
                if (s.empty() == false)
                    s.pop();
            else if (res[i] == ".")
                continue;
            else if (res[i].size() > 0)
                s.push(res[i]);
        }

        vector<string> t;
        while (s.empty() == false) {
            t.push_back("/");
            t.push_back(s.top());
            s.pop();
        }
        t.push_back("/");

        if (t.size() == 0)
            t.push_back("/");
        reverse(t.begin(), t.end());
        if (t[t.size() - 1] == "/" && t.size() > 1)
            t.pop_back();

        string w;
        std::for_each(t.begin(), t.end(), [&](const std::string &piece){ w += piece; });
        return w;
    }
};
