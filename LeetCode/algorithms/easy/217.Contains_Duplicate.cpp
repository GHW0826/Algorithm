class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> table;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = table.insert(nums[i]);
            if (it.second == false)
                return true;
        }
        return false;
    }
};


// 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();        
    }
};
