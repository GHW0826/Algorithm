class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long sum = 1;
        int zero = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++zero;
                if (zero > 1)
                    break;
                continue;
            }
            sum *= nums[i];
        }
        if (zero > 1)
            return vector<int>(nums.size(), 0);

        vector<int> answer;
        for (int i = 0; i < nums.size(); ++i) {
            auto num =  (zero > 0 && nums[i] != 0) ? 0 : 
                        (zero > 0 && nums[i] == 0) ? sum : sum / nums[i];
            answer.emplace_back(num);
        }
        return answer;
    }
};
