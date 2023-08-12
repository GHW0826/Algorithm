class Solution {
public:
    vector<string> dict = { "", "", "abc", "def", "ghi","jkl", "mno","pqrs", "tuv", "wxyz" }; // as 0 means nothing and pressing 1 results nothing here.

    void dfs(int idx, string& digits, vector<string>& answer, string word) {

        if (idx == digits.size()) {
            answer.push_back(word);
            return;
        }

        string phone_letters = dict[digits[idx] - '0'];
        for (int i = 0; i < phone_letters.size(); i++) {
            word += phone_letters[i];
            dfs(idx + 1, digits, answer, word);
            word.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if (digits.size() == 0)
            return answer;

        dfs(0, digits, answer, "");

        return answer;
    }
};
