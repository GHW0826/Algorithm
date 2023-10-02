class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' };

        for (int i = 0, j = s.size() - 1; i < j;) {
            if (vowels.find(s[i]) != vowels.end() &&
                vowels.find(s[j]) != vowels.end()) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
            if (vowels.find(s[i]) == vowels.end())
                ++i;
            if (vowels.find(s[j]) == vowels.end())
                --j;
        }

        return s;
    }
};
