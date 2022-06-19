class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> table;
        for (int i = 0; i < s.size(); ++i)
            ++table[s[i]];
        
        for (int i = 0; i < s.size(); ++i)
            if (table[s[i]] == 1)
                return i;
        
        return -1;
    }
};
