class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); ++i)
            if (++table[nums[i]] == 2)
                table.erase (nums[i]);
        return table.begin()->first;
    }
};



// good
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        int answer = 0;
	for(auto num : nums)
            answer ^= num;
	return answer;
    }
};

