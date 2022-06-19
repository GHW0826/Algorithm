class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m, vector<int>(n, 0));
        for (int i = 0; i < path[0].size(); ++i)
            path[0][i] = 1;
        for (int i = 0; i < path.size(); ++i)
            path[i][0] = 1;
        
        for (int i = 1; i < path.size(); ++i)
            for (int j = 1; j < path[i].size(); ++j)
                path[i][j] += path[i - 1][j] + path[i][j - 1];
        
        return path[m - 1][n - 1];
    }
};
