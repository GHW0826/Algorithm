class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1)
            return triangle[0][0];
        
        int triRow = triangle.size();
        for (int row = 1; row < triRow; ++row) {
            int triCol = triangle[row].size();
            for (int col = 0; col < triCol; ++col) {
                if (col == 0)
                    triangle[row][col] = triangle[row - 1][col] + triangle[row][col];
                else if (col == triCol - 1)
                    triangle[row][col] = triangle[row - 1][col - 1] + triangle[row][col];
                else {
                    triangle[row][col] = min(triangle[row - 1][col - 1] + triangle[row][col], 
                                             triangle[row - 1][col] + triangle[row][col]);
                }
            }
        }
        int answer = *min_element(triangle[triRow - 1].begin(), triangle[triRow - 1].end());
        return answer;
    }
};
