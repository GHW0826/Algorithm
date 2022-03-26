class Solution {
public:
    vector<vector<int>> answer_;
    vector<int> nums_;
    int sum_;
    int target_;
    
    void Sum(vector<int>& candidates, int start)
    {
        if (sum_ > target_)
            return;
        if (sum_ == target_) {
            answer_.emplace_back(nums_);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (sum_ < target_) {
                sum_ += candidates[i];
                nums_.push_back(candidates[i]);
                Sum(candidates, i);
                sum_ -= candidates[i];
                nums_.pop_back();
            }
            else
                return;
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum_ = 0;
        target_ = target;
        Sum(candidates, 0);
        
        return answer_;
    }
};
