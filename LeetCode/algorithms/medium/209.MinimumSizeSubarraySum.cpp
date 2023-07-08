class Solution {
public:
    int minSubArrayLen(int target, vector<int> nums) {

        if (nums.size() == 0)
            return 0;

        int sum = 0;
        int answer = 987654321;
        int i = 0, j = 0;
        while (i < nums.size()) {
            sum += nums[i];

            while (j <= i && sum >= target) {
                answer = min(answer, i - j + 1);
                sum -= nums[j];
                ++j;
            }
            ++i;
        }
        if (answer == 987654321)
            answer = 0;
        return answer;
    }
};
