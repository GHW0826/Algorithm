class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> table;
        for (int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            table[tmp].push_back(strs[i]);
        }
        
        for (const auto& it : table)
            answer.emplace_back(it.second);
        return answer;
    }
};
