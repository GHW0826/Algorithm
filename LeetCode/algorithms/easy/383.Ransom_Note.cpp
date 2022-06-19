class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> table;
        bool answer = true;
        for (int i = 0; i < magazine.size(); ++i)
            ++table[magazine[i]];

        for (int i = 0; i < ransomNote.size(); ++i) {
            --table[ransomNote[i]];
            if (table[ransomNote[i]] < 0) {
                answer = false;
                break;
            }
        }
        return answer;
    }
};
