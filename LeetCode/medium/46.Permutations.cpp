
// next_permutation
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        do {
            answer.emplace_back(vector<int>(nums));
        } while (next_permutation(nums.begin(), nums.end()));
        
        return answer;
    }
};



// no stl
class Solution {
public:
    vector<vector<int>> answer;
    vector<int> per;
    vector<bool> visit;
    int n;
    void permutation(vector<int>& nums)
    {
    	if (per.size() == n) {
            answer.emplace_back(per);
	        return;
      }
        
	    for (int i = 0; i < nums.size(); ++i) {
	        if (visit[i] == false) {
	    	    visit[i] = true;
		        per.push_back(nums[i]);
		        permutation(nums);
		        per.pop_back();
		        visit[i] = false;
            }
	    }
	}

    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        visit.resize(nums.size(), false);
        permutation(nums);
        
        return answer;
    }
};
