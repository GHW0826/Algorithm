class Solution {
public:
    int climbStairs(int n) {
        vector<int> save(46, 0);
        save[1] = 1;
        save[2] = 2;
        if (n <= 2)
            return save[n];
        
        for (int i = 3; i <= n; ++i)
            save[i] = save[i - 1] + save[i - 2];
        
        return save[n];
    }
};
