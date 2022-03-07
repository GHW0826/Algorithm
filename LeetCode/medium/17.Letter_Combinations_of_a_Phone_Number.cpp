class Solution {
public:
    vector<string> answer;
    vector<string> letter;
    string word;
    
    void order(string& digit, int index) {
        if (word.size() == digit.size()) {
            answer.emplace_back(word);
            return;
        }
        int num = digit[index] - '0';
        for (int i = 0; i < letter[num].size(); ++i) {
            word += letter[num][i];
            order(digit, index + 1);
            word.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty() == true)
            return vector<string>();
        letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        order(digits, 0);
        
        return answer;
    }
};
