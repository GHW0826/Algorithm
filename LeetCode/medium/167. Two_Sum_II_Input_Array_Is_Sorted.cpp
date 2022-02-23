class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> table;
        
        for (int i = 0; i < numbers.size(); ++i) {
            if (table[numbers[i]] > 0)
                return { table[numbers[i]], i + 1 };
            table[target - numbers[i]] = i + 1;
        }
        return vector<int>();
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() == 2)
            return { 1, 2 };
        else {
            int start = 0;
            int end = numbers.size() - 1;
            while (start < end) {
                if (target > (numbers[start] + numbers[end]))
                    start++;
                else if (target < (numbers[start] + numbers[end]))
                    end--;
                else
                    return { start + 1, end + 1 };
            }
        }
        return vector<int>();
    }
};
