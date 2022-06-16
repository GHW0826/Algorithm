class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> table;
        for (auto& it : nums1)
            ++table[it];
        
        vector<int> answer;
        for (auto& it : nums2) {
            if (table[it] > 0) {
                answer.push_back(it);
                --table[it];
            }
        }
                
        return answer;             
    }
};
