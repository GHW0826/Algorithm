

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1, n2;
        for (const auto& it : nums1)
            n1.insert(it);
        for (const auto& it : nums2)
            n2.insert(it);

        vector<int> answer;
        std::set_intersection(n1.begin(), n1.end(),
                              n2.begin(), n2.end(),
                              std::back_inserter(answer));
        return answer;
    }
};
