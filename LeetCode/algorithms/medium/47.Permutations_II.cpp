class Solution {
public:
    int size;
    set<vector<int>> answer;
    vector<int> permutation;
    vector<bool> visit;

    void permutations(vector<int>& nums, int depth) {
        if (depth == size) {
            answer.insert(permutation);
            return;
        }

        for (int i = 0; i < size; ++i) {
            if (visit[i] == false) {
                visit[i] = true;
                permutation.push_back(nums[i]);
                permutations(nums, depth + 1);
                permutation.pop_back();
                visit[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> nums) {
        size = nums.size();
        visit.resize(size, false);
        permutations(nums, 0);

        return vector<vector<int>>(answer.begin(), answer.end());
    }
};
