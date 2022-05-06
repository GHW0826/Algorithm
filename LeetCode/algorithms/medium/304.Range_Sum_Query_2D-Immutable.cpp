  - cpp
  
class NumMatrix {
public:
    vector<vector<int>> matrix_;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            vector<int> row;
            int sum = 0;
            for (int j = 0; j < cols; ++j) {
                sum += matrix[i][j];
                row.push_back(sum);
            }
            matrix_.emplace_back(row);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            if (col1 >= 1)
                sum += matrix_[i][col2] - matrix_[i][col1 - 1];
            else
                sum += matrix_[i][col2];
        }

        return sum;
    }
};
