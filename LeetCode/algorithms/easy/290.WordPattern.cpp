class Solution {
public:
    bool wordPattern(string pattern, string s) {

        std::stringstream ss(s);
        vector<string> word;
        std::string tmp;
        while (std::getline(ss, tmp, ' '))
            word.push_back(tmp);

        if (pattern.size() != word.size())
            return false;

        unordered_set<string> wordTable;
        unordered_map<char, string> table;
        for (int i = 0; i < pattern.size(); ++i) {
            if (table.find(pattern[i]) == table.end()) {
                if (wordTable.find(word[i]) != wordTable.end())
                    return false;
                table[pattern[i]] = word[i];
                wordTable.insert(word[i]);
            }
            else {
                if (table[pattern[i]] != word[i])
                    return false;
            }
        }
        return true;
    }
};
