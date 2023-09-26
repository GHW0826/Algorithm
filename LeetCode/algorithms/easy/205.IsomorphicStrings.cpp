class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        map<char, char> table;
        map<char, char> table2;
        for (int i = 0; i < s.size(); ++i) {
            if (table.find(s[i]) == table.end())
                table[s[i]] = t[i];
            else {
                if (table[s[i]] != t[i])
                    return false;
            }

            if (table2.find(t[i]) == table2.end())
                table2[t[i]] = s[i];
            else {
                if (table2[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
