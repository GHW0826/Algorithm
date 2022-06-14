class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i)
            if (find(matrix[i].begin(), matrix[i].end(), target) != matrix[i].end())
                return true;
        return false;
    }
};
