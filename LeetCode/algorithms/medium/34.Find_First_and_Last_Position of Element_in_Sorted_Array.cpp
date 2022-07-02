class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return { -1, -1 };

        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;
        while (start <= end) {
            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                break;
            mid = (start + end) / 2;
        }

        if (nums[mid] != target)
            return { -1, -1 };

        int first_idx = mid;
        while (first_idx > 0) {
            if (nums[first_idx - 1] != target)
                break;
            --first_idx;
        }
        
        int last_idx = mid;
        while (last_idx < nums.size() - 1) {
            if (nums[last_idx + 1] != target)
                break;
            ++last_idx;
        }
        
        return { first_idx, last_idx };
    }
};
