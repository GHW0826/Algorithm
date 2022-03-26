class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        return static_cast<double>(std::accumulate(salary.begin() + 1, salary.end() - 1, 0L)) / (salary.size() - 2);
    }
};
