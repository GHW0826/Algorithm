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

        int first = mid, last = mid, first_idx, last_idx;
        bool bfirst = false, blast = false;
        while (bfirst == false || blast == false) {
            if (bfirst == false) {
                if (nums[first] == target) {
                    --first;
                    if (first < 0) {
                        bfirst = true;
                        first_idx = 0;
                    }
                    else if (nums[first] != target) {
                        bfirst = true;
                        first_idx = first + 1;
                    }
                }
            }
            if (blast == false) {
                if (nums[last] == target) {
                    ++last;
                    if (last >= nums.size()) {
                        blast = true;
                        last_idx = nums.size() - 1;
                    }
                    else if (nums[last] != target) {
                        blast = true;
                        last_idx = last - 1;
                    }
                }
            }
        }
        return { first_idx, last_idx };
    }
};
